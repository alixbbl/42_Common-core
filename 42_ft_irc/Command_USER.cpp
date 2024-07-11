#include "Server.hpp"
#include "Commands.hpp"
#include "Replies.hpp"
#include "Client.hpp"

/*
Command: USER
	Parameters: <username> <hostname> <servername> :<realname>
si on ignore la communication inter-srveurs, on ignore les params
<hostname>  et <servername>
*/

void	handleUSERCommand(Server& server, Client* client, cmdStruct* command) {

	std::string reply = "Connexion failure.\r\n";
	int connexion = client->getConnectionStatus();

	if (connexion == 3) {

		if (command->params.size() != 4 || command->message.empty()) {
			reply = NEEDMOREPARAMS_ERR(command->params[0]);
			sendBytesToClient(client, reply.c_str()); return ;
		}

		client->setUserName(command->params[1]);
		server.setServerName(command->params[3]);
		client->setRealName(command->message);
		connexion = 4;
		client->setConnectionStatus(connexion);
		reply = RPL_WELCOME(client->getUserName(), client->getNickname()).c_str();
	}
	sendBytesToClient(client, reply.c_str());
}
