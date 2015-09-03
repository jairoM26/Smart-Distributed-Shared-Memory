/*
 * Server.h
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#ifndef SOCKET_SERVER_H_
#define SOCKET_SERVER_H_

#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../DataStructure/LinkedList.h"
#include "SocketConstants.h"

using namespace std;

class Server : public SocketConstants
{
public:

	Server();
	virtual ~Server();
	void setServer(int port);
	static void* connectionManager(void* arg);
	static LinkedList<string>* messages_list;
	string getPrimerMensaje();

private:
	int socket_desc , client_sock , c;
	struct sockaddr_in server , client;
};

#endif /* SOCKET_SERVER_H_ */
