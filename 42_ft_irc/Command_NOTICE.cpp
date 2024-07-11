#include "Server.hpp"
#include "Commands.hpp"
#include "Replies.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include <vector>

/*
Command: NOTICE
   Parameters: <nickname> <text>
*/

void handleNOTICECommand(Server& server, Client* client, cmdStruct* command) {

	const std::string message = command->message;
	std::vector<std::string> receiversList;
	std::string reply = "";
	std::map<const int, Client*> clientsList = server.getClients();
	std::map<std::string, Channel *> channelsList = server.getChannels();
	std::vector<std::string> errorMessages;

	if (command->params.size() == 1) {

		reply = ERR_NORECIPIENT(command->params[0]);
		sendBytesToClient(client, reply.c_str());
		return;
	}
	else if (!command->params[1].empty()) {

		std::istringstream iss(command->params[1]);
		std::string receiver;
		while (std::getline(iss, receiver, ','))
			receiversList.push_back(receiver);
	}
	else if (command->message.empty()) {

		reply = ERR_NOTEXTTOSEND;
		sendBytesToClient(client, reply.c_str());
		return;
	}

	for (size_t i = 0; i < receiversList.size(); i++) {

		// si c'est un format channel
		if (!receiversList[i].empty() && receiversList[i][0] == '#') {
			std::string channelReceiving = receiversList[i];
			bool channelFound = false;

			for (std::map<std::string, Channel*>::iterator it = channelsList.begin();
				it != channelsList.end(); it++) {
				if (it->first == channelReceiving) {
					sendBytesToChannel(it->second, command->message.c_str());
					channelFound = true;
					break;
				}
			}
			if (!channelFound)
				errorMessages.push_back(ERR_CANNOTSENDTOCHAN(channelReceiving));
		}
		// si c'est un format user
		else if (!receiversList[i].empty()) {

			std::string userReceiving = receiversList[i];
			std::string senderPrefix = ":" + client->getNickname() + "!" + "localhost";
			std::string message = senderPrefix + " NOTICE " + userReceiving + " :" + command->message.erase(0, 1) + "\r\n";
			bool userFound = false;

			for (std::map<const int, Client*>::iterator it = clientsList.begin();
        		it != clientsList.end(); it++) {

        		if (it->second->getNickname() == userReceiving) {
            		userFound = true;
            		sendBytesToClient(it->second, message.c_str());
            		break; }
    		}
			if (!userFound)
				errorMessages.push_back(ERR_NOSUCHNICK(userReceiving));
		}
		else
			errorMessages.push_back(ERR_NOSUCHNICK(command->params[1]));
	}
	for (std::vector<std::string>::const_iterator it = errorMessages.begin();
		it != errorMessages.end(); ++it)
		sendBytesToClient(client, it->c_str());
}
