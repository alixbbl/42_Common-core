#include "Server.hpp"
#include "Commands.hpp"
#include "Replies.hpp"
#include "Channel.hpp"
#include <ctime>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

# define ERR_NEEDMOREPARAMS 461
# define ERR_NOSUCHCHANNEL 403
# define ERR_CHANOPRIVSNEEDED 482
# define ERR_NOTONCHANNEL 442

//command = PART <channel>{,<channel>} [<reason>]

bool	handlePartErrors(Client *client, Channel* channel, std::string &user, cmdStruct* command) {

	std::string reply;
	if (command->params.size() < 2)
		reply = NEEDMOREPARAMS_ERR(command->params[0]);
	else if (!channel)
		reply = NOSUCHCHANNEL_ERR(channel->getChannelName());
	else if (!channel->isClient(user))
		reply = NOTONCHANNEL_ERR(user, channel->getChannelName());
	if (!reply.empty()) {
		sendBytesToClient(client, reply.c_str());
		return true;
	}
	return false;
}

void handlePARTCommand(Server& server, Client* client, cmdStruct* command) {

	std::string reply;
	std::vector<std::string> chanToLeave;

	if (command->params[1].find(",") != std::string::npos) {
		std::istringstream iss(command->params[1]);
		std::string chan;
		while (std::getline(iss, chan, ','))
			chanToLeave.push_back(chan);
	}
	else
		chanToLeave.push_back(command->params[1]);

	for (std::vector<std::string>::iterator it = chanToLeave.begin(); it != chanToLeave.end(); it++) {

		std::string channelName = *it;
		if (!channelName.empty() and channelName[0] != '#')
			channelName.insert(0, "#");
		Channel *channel = server.getChannels()[channelName];
		std::string user = client->getNickname();

		if (handlePartErrors(client, channel, user, command))
			continue ;

		channel->removeClientFromChan(user);
		if (channel->isOperator(user))
			channel->removeOperator(user);
		for (std::vector< std::string >::iterator it = client->getJoinedChan().begin(); it != client->getJoinedChan().end(); it++) {
			if (*it == channel->getChannelName()) {
				client->getJoinedChan().erase(it);
				break;
			}
		}
		reply = RPL_PART(userID(client->getNickname(), client->getUserName()), channelName, command->message);
		sendBytesToClient(client, reply.c_str());
		sendBytesToChannel(channel, reply.c_str());
	}
	return ;
}
