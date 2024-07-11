#include "Server.hpp"
#include "Commands.hpp"
#include "Replies.hpp"
#include "Client.hpp"
#include <cstring>

void	handlePASSCommand(Server& server, Client* client, cmdStruct* command) {

	std::string reply = "Connexion failure PASS.";
	int connexion = client->getConnectionStatus();

	if (command->params.empty()) {

		reply = NEEDMOREPARAMS_ERR(command->params[0]);
		ssize_t bytes_transfered = send(client->getClientSocket(), reply.c_str(), sizeof(reply) - 1, 0);
		if (bytes_transfered <= 0)
			std::cout << "Server failed to send a reply to client." << std::endl;
	}
	else if (connexion == 2) {

		reply = ALREADYREGISTRED_ERR;
		sendBytesToClient(client, reply.c_str());
		return ;
	}
	else if ((connexion == 1) && (command->params[1] == server.getPassWord())
		&& command->params.size() == 2) {

		reply = "Password accepted.\r\n";
		connexion = 2;
		client->setConnectionStatus(connexion);
	}
	sendBytesToClient(client, reply.c_str());
}
