#include "Server.hpp"
#include "Commands.hpp"
#include "Replies.hpp"
#include "Channel.hpp"
#include <map>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string>

# define ERR_NEEDMOREPARAMS 461
# define ERR_NOSUCHCHANNEL 403
# define ERR_CHANOPRIVSNEEDED 482
# define ERR_NOTONCHANNEL 442
# define ERR_UNKNOWNMODE 472

//command = MODE <target> [<modestring> [<mode arguments>...]]

bool	handleModeErrors(Client *client, Channel* channel, std::string &user, cmdStruct* command) {

	std::string reply;
	std::string modestring;
	if (!channel->getMode().empty())
		modestring = channel->getMode() + "\r\n";
	if (command->params.size() <= 1)
		reply = NEEDMOREPARAMS_ERR(command->params[0]);
	else if (command->params.size() == 2)
		reply = RPL_CHANNELMODEIS(user, command->params[1], modestring);
	else if (!channel->isOperator(user))
		reply = CHANOPRIVSNEEDED_ERR(channel->getChannelName());
	if (!reply.empty()) {
		sendBytesToClient(client, reply.c_str());
		return true;
	}
	return false;
}

void handleMODECommand(Server& server, Client* client, cmdStruct* command) {

	std::string reply;
	std::string channelName = command->params[1];
	if (!channelName.empty() and channelName[0] != '#') {
		for (std::map<const int, Client * >::iterator it = server.getClients().begin(); it != server.getClients().end(); it++) {
			if ((it->second)->getNickname() == command->params[1])
				return ;
		}
		channelName.insert(0, "#");
	}
	Channel *channel = server.getChannels()[channelName];
	if (!channel)
		return ;
	std::string user = client->getNickname();

	if (!channel or handleModeErrors(client, channel, user, command) or
		(command->params[2][0] != '-' and command->params[2][0] != '+'))
		return;

	int remove;
	std::vector<std::string> modeParams;
	size_t nbParams = command->params.size() - 3;

	std::vector<std::string>::iterator itParam;
	if (nbParams > 0) {
		for (size_t i = 0; i < nbParams; i++)
			modeParams.push_back(command->params[i + 3]);
	}
	else if (!nbParams)
		modeParams.push_back("");
	itParam = modeParams.begin();

	for (size_t i = 0; command->params[2][i]; i++) {
		
		std::vector<std::string>::iterator itTmp = itParam;
		switch (command->params[2][i]) {
			case ('-'):
				remove = 1;
				break;

			case ('+'):
				remove = 0;
				break;

			case ('o'):
				if ((*itParam).empty())
					break;
				if (remove) {
					if (channel->isClient(*itParam) and channel->isOperator(*itParam)) {
						channel->removeOperator(*itParam);
						reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "-o", *itParam);
					}
				}
				else {
					if (channel->isClient(*itParam) and !channel->isOperator(*itParam)) {
						channel->addOperators(*itParam);
						reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "+o", *itParam);
					}
				}
				if (++itTmp != modeParams.end())
					itParam++;
				else 
					*itParam = "";
				sendBytesToChannel(channel, reply.c_str());
				break ;

			case ('t'):
				if (remove) {
					if (channel->getMode().find("t") != std::string::npos) {
						channel->removeMode("t");
						reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "-t", "");
					}
				}
				else {
					if (channel->getMode().find("t") == std::string::npos) {
						channel->addMode("t");
						reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "+t", "");
					}
				}
				sendBytesToChannel(channel, reply.c_str());
				break ;

			case ('i'):
				if (remove) {
					if (channel->getMode().find("i") != std::string::npos) {
						channel->removeMode("i");
						reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "-i", "");
					}
				}
				else {
					if (channel->getMode().find("i") == std::string::npos) {
						channel->addMode("i");
						reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "+i", "");
					}
				}
				sendBytesToChannel(channel, reply.c_str());
				break ;

			case ('l'):
				if (remove) {
					if (channel->getMode().find("l") != std::string::npos) {
						channel->removeMode("l");
						reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "-l", "");
					}
				}
				else {
					if (channel->getMode().find("l") == std::string::npos) {
						if ((*itParam).empty())
							break;
						std::istringstream lim(*itParam);
						int nb;
						if (lim >> nb) {
							channel->setNbrUsersLimit(nb);
							channel->addMode("l");
							reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "+l", *itParam);
						}
						else
							break;
					}
					if (++itTmp != modeParams.end())
						itParam++;
					else 
						*itParam = "";
				}
				sendBytesToChannel(channel, reply.c_str());
				break ;

			case ('k'):
				if (remove) {
					if (channel->getMode().find("k") != std::string::npos) {
						channel->removeMode("k");
						if (!channel->getChannelPwd().empty())
							channel->getChannelPwd().clear();
						reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "-k", "");
					}
				}
				else {
					if (channel->getMode().find("k") == std::string::npos) {
						if ((*itParam).empty())
							break;
						channel->addMode("k");
						channel->setChannelPwd(*itParam);
						reply = RPL_MODE(userID(client->getNickname(), client->getUserName()), channelName, "+k", *itParam);
						if (++itTmp != modeParams.end())
							itParam++;
						else 
							*itParam = "";
					}
					else {
						reply = KEYSET_ERR(channelName);
						sendBytesToClient(client, reply.c_str());
					}
				}
				sendBytesToChannel(channel, reply.c_str());
				break ;

			default :
				reply = UNKNOWNMODE_ERR(command->params[2][1], channelName);
				sendBytesToClient(client, reply.c_str());
				break;
		}
	}
	return ;
}
