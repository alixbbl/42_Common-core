#include "Server.hpp"
#include "Commands.hpp"
#include "Replies.hpp"
#include "Channel.hpp"
#include <ctime>
#include <cstring>

# define ERR_NEEDMOREPARAMS 461
# define ERR_NOSUCHCHANNEL 403
# define ERR_CHANOPRIVSNEEDED 482
# define ERR_NOTONCHANNEL 442

//command = TOPIC <channel> [<topic>]

bool	handleTopicErrors(Client *client, Channel* channel, std::string &user, cmdStruct* command) {

	std::string reply;
	if (command->params.size() != 2)
		reply = NEEDMOREPARAMS_ERR(command->params[0]);
	else if (!channel or channel->getClientsList().empty())
		reply = NOSUCHCHANNEL_ERR(command->params[1]);
	else if (!channel->isClient(user))
		reply = NOTONCHANNEL_ERR(user, command->params[1]);
	else if (channel->getMode().find("t") != std::string::npos and !channel->isOperator(user) and !command->message.empty())
		reply = CHANOPRIVSNEEDED_ERR(command->params[1]);
	if (!reply.empty()) {
		sendBytesToClient(client, reply.c_str());
		return true;
	}
	return false;
}

void handleTOPICCommand(Server& server, Client* client, cmdStruct* command) {
	std::string reply;
	std::string channelName = command->params[1];
	if (!channelName.empty() and channelName[0] != '#')
		channelName.insert(0, "#");
	Channel *channel = server.getChannels()[channelName];
	std::string user = client->getNickname();

	if (handleTopicErrors(client, channel, user, command))
		return;

	std::time_t timestamp = std::time(NULL);
	std::string timeString = std::ctime(&timestamp);

	if (!command->message.empty()) {
		channel->getTopic().clear();
		if (command->message.size() > 1) {
			channel->setTopic(command->message.erase(0, 1));
			reply = userID(user, client->getUserName()) + " TOPIC " + channelName + " :" + command->message + "\r\n";
			sendBytesToChannel(channel, reply.c_str());
		}
	}
	else {
		if (!channel->getTopic().empty()) {
			reply = RPL_TOPIC(user, channelName, channel->getTopic());
			sendBytesToClient(client, reply.c_str());
			reply = RPL_TOPICWHOTIME(user, channelName, client->getNickname(), timeString);
			sendBytesToClient(client, reply.c_str());
		}
		else {
			reply = RPL_NOTOPIC(user, channelName);
			sendBytesToClient(client, reply.c_str());
		}
	}
	return ;
}

