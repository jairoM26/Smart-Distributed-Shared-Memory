/*
 * Client.h
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#ifndef SOCKET_CLIENT_H_
#define SOCKET_CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include "../DataStructure/LinkedList.h"

using namespace std;

class Client {

private:
	static int _SendPort;
	static char* _IP;
	static LinkedList<string>* _MessagesList;
	static pthread_mutex_t mutex;
public:
	Client(char* pIP,int pPort);
	static void* threadSendToPort(void* pData);
	static void error(const char *msg);
	static void receiveMessage(string pMsj);
};


#endif /* SOCKET_CLIENT_H_ */
