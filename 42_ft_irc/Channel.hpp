#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <map>
#include <vector>
#include "Client.hpp"
#include <ctime>
#pragma once

class Client;
class Channel {

	private:
		std::vector<std::string>		_operators;
		std::vector<std::string>		_kicked;
		std::vector<std::string> 		_invited;
		std::map<std::string, Client*>	_clients;
		std::string 					_name;
		std::string						_channelPwd;
		std::string						_topic;
		std::string						_mode;
		std::string						_creationTime;
		size_t							_nbrUsersLimit;

	public:
		Channel(const std::string &name);
		~Channel();

		std::map<std::string, Client*>&	getClientsList();
		size_t							getNbrUsersLimit( void );
		std::string&					getChannelName( void );
		std::string&					getChannelPwd( void );
		std::string&					getTopic( void );
		std::string&					getMode( void );
		std::vector<std::string>&		getKicked( void );
		std::vector<std::string>&		getInvited();
		std::vector<std::string>&		getOperators( void );

		void							setNbrUsersLimit(int limit);
		void							setChannelPwd(std::string channelPwd);
		void							setTopic(std::string topic);
		void							addMode(std::string mode);
		void							removeMode(std::string mode);

		bool							isClient(std::string &nickname);
		bool							isInvited(std::string &nickname);
		bool							isOperator(std::string &nickname);
		bool							isKicked(std::string &nickname);

		void							removeOperator(std::string &nickname);
		void							removeKicked(std::string &nickname);
		void							removeClientFromChan(std::string &nickname);
		void							removeClientFromInvite(std::string &nickname);
		void							addToChan(Client *client);
		void							addToInvited(std::string &nickname);
		void							addToKicked(std::string &nickname);
		void							addOperators(std::string &nickname);
};
