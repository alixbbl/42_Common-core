#include "Server.hpp"
#include "Commands.hpp"
#include "Signals.hpp"
/*
	Pour un test en nc, on entre "nc localhost 6667", apres avoir lancé le
	serveur sur le port voulu avec le mdp. Ensuite, on entre manuellement
	dans le client nc, les commandes de connexion dans l'ordre, se terminant
	toutes par CTRL+V+M + Enter.
*/

int main(int ac, char **av) {

	if (ac != 3)
		return (std::cout << "Too few arguments." << std::endl, -1);

	Server server(av[1], av[2]);
	SignalMonitor monitoring(server);

	while (true) {

		int numEvents = epoll_wait(server.getEpollFd(), server.getEventsTab(), 1024, -1);
		if (numEvents < 0)
			return -1;

		for (int i = 0; i < numEvents; ++i) {
			if (server.getEventsTab()[i].data.fd == server.getServerSocket()) {
				Client* newClient = new Client;
				try {
					int tmp = accept(server.getServerSocket(), (struct sockaddr*)&newClient->getClientAddr(),
						&newClient->getClientAddrLen());
					newClient->setClientSocket(tmp);
					if (newClient->getClientSocket() < 0)
						throw Client::clientConnectFailure();
					fcntl(newClient->getClientSocket(), F_SETFL, O_NONBLOCK);
					server.getEvent().events = EPOLLIN;
					server.getEvent().data.fd = newClient->getClientSocket();
					if (epoll_ctl(server.getEpollFd(), EPOLL_CTL_ADD, newClient->getClientSocket(), &server.getEvent()) < 0) {
						throw Client::clientConnectFailure(); }
					server.getClients()[newClient->getClientSocket()] = newClient;
				}
				catch (const std::exception &e) { std::cout << e.what() <<std::endl ; close(newClient->getClientSocket()); }
			}
			else
				processEvent(server, i);
		}
	}
	server.handleDisconnect();
	close(server.getEpollFd());
	return 0;
}

