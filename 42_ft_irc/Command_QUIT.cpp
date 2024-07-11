#include "Server.hpp"
#include "Commands.hpp"
#include "Replies.hpp"
#include "Client.hpp"

/*
Command: QUIT
   Parameters: [ <Quit Message> ]
*/

void	handleQUITCommand(Server& server, Client* client, cmdStruct* command) {

	if (command->params.size() > 2)
		return ;

	std::string user = client->getNickname();
	std::string reply;
	std::string reason = "Quit: ";

	if (!command->message.empty())
		reason += command->message;
	else	
		reason += "leaving";

	for (std::vector< std::string >::iterator it = client->getJoinedChan().begin();
			it != client->getJoinedChan().end(); it++) {
		Channel *channel = server.getChannels()[*it];
		channel->removeClientFromChan(user);
		if (channel->isOperator(user))
			channel->removeOperator(user);
		reply = RPL_QUIT(userID(client->getNickname(), client->getUserName()), reason);
		sendBytesToChannel(channel, reply.c_str());
	}
	sendBytesToClient(client, reply.c_str());
	server.removeClient(client->getNickname());
}
