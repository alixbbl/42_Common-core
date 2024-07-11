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

//command = JOIN <channel>{,<channel>} [<key>{,<key>}]
class Channel;

bool joinChannel(Channel *channel, Client* client, std::string key) {

	std::string reply;
	if (channel->getMode().find("i") != std::string::npos) {
		    std::vector<std::string>::iterator it = std::find(channel->getInvited().begin(), channel->getInvited().end(), client->getNickname());
			if (it == channel->getInvited().end()) {
				reply = ERR_INVITEONLYCHAN(client->getNickname(), channel->getChannelName());
				sendBytesToClient(client, reply.c_str());
				return false;
			}
	}
	if (channel->getMode().find("k") != std::string::npos) {
			if (channel->getChannelPwd() != key) {
				reply = ERR_BADCHANNELKEY(client->getNickname(), channel->getChannelName());
				sendBytesToClient(client, reply.c_str());
				return false;
			}
	}
	if (channel->getMode().find("l") != std::string::npos) {
			if (channel->getClientsList().size() >= static_cast<size_t>(channel->getNbrUsersLimit())) {
				reply = ERR_CHANNELISFULL(client->getNickname(), channel->getChannelName());
				sendBytesToClient(client, reply.c_str());
				return false;
			}
	}
	if (channel->getMode().find("i") != std::string::npos)
		channel->removeClientFromInvite(client->getNickname());
	channel->addToChan(client);
	client->addJoinedChan(channel->getChannelName());

	reply = userID(client->getNickname(), client->getUserName()) + " JOIN " + channel->getChannelName() + "\r\n";
	sendBytesToChannel(channel, reply.c_str());

	if (!channel->getTopic().empty()) {
		reply = RPL_TOPIC(client->getNickname(), channel->getChannelName(), channel->getTopic());
		sendBytesToClient(client, reply.c_str());
	}
	else {
		reply = RPL_NOTOPIC(client->getNickname(), channel->getChannelName());
		sendBytesToClient(client, reply.c_str());
	}

	std::string list;
	for (std::map< std::string, Client* >::iterator it = channel->getClientsList().begin(); it != channel->getClientsList().end(); it++) {
		if (channel->isOperator((it->second)->getNickname()))
			list += "@";
		list += (it->second)->getNickname();
		std::map<std::string, Client * >::iterator nextIt = it;
    	++nextIt;
		if (nextIt != channel->getClientsList().end())
			list += " ";
	}

	reply = RPL_NAMREPLY(client->getNickname(), channel->getChannelName(), list);
	sendBytesToClient(client, reply.c_str());
	reply = RPL_ENDOFNAMES(client->getNickname(), channel->getChannelName());
	sendBytesToClient(client, reply.c_str());
	return true;
}

void handleJOINCommand(Server& server, Client* client, cmdStruct* command) {

	std::string reply;
	if (command->params.size() < 2) {
		reply = NEEDMOREPARAMS_ERR(command->params[0]);
		sendBytesToClient(client, reply.c_str());
		return ;
	}
	std::map<std::string, std::string> chanToJoin;
	std::string user = client->getNickname();

	if (command->params[1].find(",") != std::string::npos and command->params.size() > 2) {
		std::istringstream iss1(command->params[1]);
		std::istringstream iss2(command->params[2]);
		std::string chan, key;
		while (std::getline(iss1, chan, ',')) {
			if (std::getline(iss2, key, ','))
				chanToJoin[chan] = key;
		}
	}
	else if (command->params[1].find(",") != std::string::npos) {
		std::istringstream iss1(command->params[1]);
		std::string chan, key;
		while (std::getline(iss1, chan, ','))
			chanToJoin[chan] = key;
	}
	else if (command->params.size() > 2)
		chanToJoin[command->params[1]] = command->params[2];
	else
		chanToJoin[command->params[1]] = "";

	for (std::map<std::string, std::string >::iterator chanCmd = chanToJoin.begin();
			chanCmd != chanToJoin.end(); chanCmd++) {

		std::string channelName = chanCmd->first;
		if (!channelName.empty() and channelName[0] != '#')
			channelName.insert(0, "#");
		Channel *channel = server.getChannels()[channelName];
		if (!channel) {
			reply = NOSUCHCHANNEL_ERR(channelName);
			sendBytesToClient(client, reply.c_str());
			channel = new Channel(chanCmd->first);
			server.getChannels()[channel->getChannelName()] = channel;
			channel->addOperators(user);
		}
		joinChannel(channel, client, chanCmd->second);
	}
	return ;
}
