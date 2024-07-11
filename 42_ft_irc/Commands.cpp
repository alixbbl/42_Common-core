#include "Server.hpp"
#include "Commands.hpp"

/************************ FONCTIONS SUPPORTS **************************/

typedef void (*cmdFunction)(Server&, Client*, cmdStruct*);

void sendBytesToClient(Client* client, const char* reply) {

	ssize_t bytes_transfered = send(client->getClientSocket(), reply, strlen(reply), 0);
	if (bytes_transfered < 0) {
		std::cout << "Error sending data to client." << std::endl;
	}
}

void	sendBytesToChannel(Channel* channel, const char* reply) {

	std::string channelName = channel->getChannelName();
	for (std::map<std::string, Client *>::iterator it = channel->getClientsList().begin();
			it != channel->getClientsList().end(); it++) {
			sendBytesToClient(it->second, reply);
	}
}

/************************ TRAITEMENT DE COMMANDE **************************/

void executeCmd(Server& server, Client* client, cmdStruct* cmdCut) {

	if (!cmdCut->params.empty()) {

		std::string cmdName = cmdCut->params[0];
		std::map< std::string, cmdFunction >& cmdList = server.getCmdList();
		std::map<std::string, cmdFunction>::iterator it = cmdList.find(cmdName);
		if (it != cmdList.end())
			it->second(server, client, cmdCut);
	}
}

void	processCmd(Server& server, Client* client, std::string cmdFull) {

	cmdStruct	cmdCut;
	size_t		nextSpace = cmdFull.find(' ');
	size_t		colon = cmdFull.find(':');

	if (!colon and cmdFull[colon + 1] != ' ') {
		cmdCut.prefix = cmdFull.substr(0, nextSpace - 1);
		cmdFull.erase(0, cmdCut.prefix.size());
	}
	if (colon and colon != std::string::npos) {
		cmdCut.message = cmdFull.substr(colon, *cmdFull.end() - 1);
		cmdFull.erase(colon, cmdCut.message.size() + 1);
	}
	std::istringstream iss(cmdFull);
	std::string token;
	while (std::getline(iss, token, ' ')) {
		if (!token.empty())
			cmdCut.params.push_back(token);
	}
	executeCmd(server, client, &cmdCut);
}

void processEvent(Server& server, int i) {

	char 	buffer[512];
	int 	clientSocket = server.getEventsTab()[i].data.fd;
	Client 	*client = server.getClients()[clientSocket];

	ssize_t bytes_transfered = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
	if (bytes_transfered < 0) {

		std::cout << "Error receiving data from client." << std::endl;
		close(clientSocket);
	}
	else {
		buffer[bytes_transfered] = '\0';
		std::string receivedData(buffer);
		if (!client->getBuffer().empty())
			receivedData = client->getBuffer() + receivedData;
		std::string cmdFull;
		size_t pos;
		while ((pos = receivedData.find("\r\n")) != std::string::npos) {

			cmdFull = receivedData.substr(0, pos);
			receivedData.erase(0, pos + 2);
			processCmd(server, client, cmdFull);
		}
		if (!receivedData.empty()) {
			client->setBuffer(receivedData);
			size_t len = receivedData.size();
			receivedData.erase(0, len);
		}
	}
}
