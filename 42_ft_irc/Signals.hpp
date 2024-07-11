#include <iostream>
#include <csignal>
#include "Server.hpp"

#pragma once

class Server;
class SignalMonitor {

	public:
	SignalMonitor(Server &server);
	~SignalMonitor();

	private:
		static Server* serverInstance;
		static void		handleSignal(int signal);
};
