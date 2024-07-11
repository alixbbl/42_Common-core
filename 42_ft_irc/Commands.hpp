#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <vector>
#include "Client.hpp"
#include "Channel.hpp"
#pragma once

class Server;
class Channel;

struct cmdStruct {

	std::string					prefix;
	std::vector<std::string>	params;
	std::string					message;

};

void 		processEvent(Server& server, int i);
void		processCmd(Server& server, Client* client, std::string cmdFull);
void		executeCmd(Server& server, Client* client, cmdStruct *cmdCut);

void		sendBytesToClient(Client* client, const char* reply);
void		sendBytesToChannel(Channel* channel, const char* reply);
void		handleCAP_LSCommand(Server& server, Client* client, cmdStruct* command);
void		handlePASSCommand(Server& server, Client* client, cmdStruct* command);
int			handleNICKErrors(Server& server, Client* client, cmdStruct* command);
void		informAllClientsOfNickChange(Server& server, Client* client, std::string oldNickname);
void		handleNICKCommand(Server& server, Client* client, cmdStruct* command);
void		handleUSERCommand(Server& server, Client* client, cmdStruct* command);
void		handlePINGCommand(Server& server, Client* client, cmdStruct* command);
void		handlePONGCommand(Server& server, Client* client, cmdStruct* command);
void		handleQUITCommand(Server& server, Client* client, cmdStruct* command);
void		handlePRIVMSGCommand(Server& server, Client* client, cmdStruct* command);
void		handleNOTICECommand(Server& server, Client* client, cmdStruct* command);
void		handleJOINCommand(Server& server, Client* client, cmdStruct* command);
bool		handlePartErrors(Client *client, Channel* channel, std::string &user, cmdStruct* command);
void		handlePARTCommand(Server& server, Client* client, cmdStruct* command);
void		handleKICKCommand(Server& server, Client* client, cmdStruct* command);
void		handleINVITECommand(Server& server, Client* client, cmdStruct* command);
void		handleTOPICCommand(Server& server, Client* client, cmdStruct* command);
void		handleMODECommand(Server& server, Client* client, cmdStruct* command);


class dataTransferError : public std::exception {
		public:
		virtual const char* what() const throw() {
			return "Error : failure in sending or receiving.";
		}
};
