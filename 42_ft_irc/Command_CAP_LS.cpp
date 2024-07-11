#include "Server.hpp"
#include "Commands.hpp"
#include "Replies.hpp"
#include "Client.hpp"
#include <cstring>

void handleCAP_LSCommand(Server& server, Client* client, cmdStruct* command) {

	std::string reply = "Connexion failure CAP.\r\n";
	int connexion = client->getConnectionStatus();

	(void)server;
	if (connexion == 0 && command->params.size() == 2)
	{
		if (command->params[1] == "LS") {
			connexion = 1;
			client->setConnectionStatus(connexion);
			reply = "CAP_ACK LS\r\n";
		}
	}
	sendBytesToClient(client, reply.c_str());
}
