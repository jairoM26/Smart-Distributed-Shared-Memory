/*
 * Client.cpp
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#include "Client.h"

int Client::_SendPort = 0;
char* Client::_IP;
LinkedList<string>* Client::_MessagesList;
pthread_mutex_t Client::mutex = PTHREAD_MUTEX_INITIALIZER;

Client::Client(char* pIP,int pPort) {
	_SendPort = pPort;
	_IP = pIP;
	_MessagesList = new LinkedList<string>();
	pthread_t hilo;
	pthread_create(&hilo,0,Client::threadSendToPort,(void*)this);
}

void* Client::threadSendToPort(void* pData){
	int sockfd, n;
	    struct sockaddr_in serv_addr;
	    struct hostent *server;

	    char buffer[256];
	    sockfd = socket(AF_INET, SOCK_STREAM, 0);
	    if (sockfd < 0)
	        error("ERROR opening socket");
	    server = gethostbyname(_IP);
	    if (server == NULL) {
	        fprintf(stderr,"ERROR, no such host\n");
	        exit(0);
	    }
	    bzero((char *) &serv_addr, sizeof(serv_addr));
	    serv_addr.sin_family = AF_INET;
	    bcopy((char *)server->h_addr,
	         (char *)&serv_addr.sin_addr.s_addr,
	         server->h_length);
	    serv_addr.sin_port = htons(_SendPort);
	    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
	        error("ERROR connecting");
	    cout << "me conecté" << endl;
	    while(true){
	    	sleep(0.3);
	    	pthread_mutex_lock(&mutex);
			bzero(buffer,256);
			//fgets(buffer,255,stdin);
			while(_MessagesList->getLen()>0){
				const char *cstr = _MessagesList->getHead()->getData().c_str();
				//const char* data = _MessagesList->getHead()->getData().c_str();
				n = write(sockfd, cstr ,strlen(cstr));n = write(sockfd, cstr ,strlen(cstr));

				if (n < 0)
					 error("ERROR writing to socket");
				cout<<"El mensaje a enviado: "<<_MessagesList->getHead()->getData()<<"\n";
				//n = read(sockfd,buffer,255);
				//cout<<"El mensaje a recibido: "<<buffer<<"\n";
				_MessagesList->deleteData(_MessagesList->getHead()->getData());
			}
			pthread_mutex_unlock(&mutex);
			bzero(buffer,256);
			if (n < 0)
				 error("ERROR reading from socket");
			//printf("%s\n",buffer);

	    }
	    close(sockfd);
	    pthread_exit(NULL);
}

void Client::error(const char *msg)
{
    perror(msg);
    exit(1);
}

void Client::receiveMessage(string pMsj){
	_MessagesList->insertData(pMsj);
}

