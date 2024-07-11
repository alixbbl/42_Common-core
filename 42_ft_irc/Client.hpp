#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <vector>
#pragma once

class Client
{
    public:
        Client();
        ~Client();
        sockaddr_in& 	getClientAddr(void);
        socklen_t& 	    getClientAddrLen(void);
        int 	        getClientSocket(void);
        std::string&    getBuffer(void);
        std::string&    getNickname(void);
        std::string&    getUserName(void);
        std::string&    getRealName(void);
        std::vector<std::string>&    getJoinedChan(void);
        int             getConnectionStatus(void);

        void            setConnectionStatus(int& connexion);
        void 	        setClientSocket(int& fd);
        void            setBuffer(std::string &buffer);
        void            setNickname(std::string& nickname);
        void            setUserName(std::string& nickname);
        void            setRealName(std::string& nickname);
        void            addJoinedChan(std::string& channelName);

        class clientConnectFailure : public std::exception {
            public:
            virtual const char* what() const throw();
        };

    private:
        struct sockaddr_in          _clientAddr;
        socklen_t                   _clientAddrLen;
        int                         _clientSocket;
        std::string                 _buffer;
        std::string                 _nickname;
        std::string                 _userName;
        std::string                 _realName;
        std::vector<std::string>    _joinedChan;
        int                         _connexion;
};
