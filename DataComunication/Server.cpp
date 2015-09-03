/*
 * Server.cpp
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#include "Server.h"

LinkedList<string>* Server::messages_list = 0;

/**
 * Class Constructor
 */
Server::Server() {
	// TODO Auto-generated constructor stub
	socket_desc = -1;
	client_sock = -1;
	c = 0;
	messages_list = new LinkedList<std::string>();
}

/**
 * Class Destructor
 */
Server::~Server() {
	// TODO Auto-generated destructor stub
}

/**
 *Esta clase recibe el puerto por el cual se abrirá un servidor y este
 * @param puerto puerto al cual se van a conectar clientes
 */
void Server::setServer(int port)
{
	//Se crea el socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_desc < 0)
	{
		printf(ERROR_AL_CREAR_SOCKET);
		exit(1);
	}
	if(DEBUGGEAR == true)
		printf(SE_HA_CREADO_EL_SOCKET);

	//se prepara la estructura del sock_addr
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);

	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror(ERROR_EN_EL_BIND);
		exit(1);
	}

	listen(socket_desc, 3);

	if(DEBUGGEAR == true)
		puts(ESPERANDO_CONEXIONES);

	c = sizeof(struct sockaddr_in);

	pthread_t thread_id[100];
	int connection_len = 0;

	while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) && connection_len < 100)
	{
		if(DEBUGGEAR == true)
			puts(SE_ESTABLECIO_UNA_CONEXION);

		if(pthread_create(&thread_id[connection_len], NULL, connectionManager, (void*) &client_sock) < 0)
		{
			perror(NO_SE_PUEDE_CREAR_THREAD);
			exit(1);
		}
		else if(pthread_create(&thread_id[connection_len], NULL, connectionManager, (void*) &client_sock) < 0)
		{
			if(DEBUGGEAR == true)
				puts(ASIGNACION_DEL_MANEJADOR);
			connection_len++;
			std::cout << "cant conec: " << connection_len << std::endl;
			pthread_join(thread_id[connection_len], NULL);
		}
		if(client_sock < 0)
		{
			perror(FALLO_ACEPTAR_LA_CONEXION);
			exit(1);
		}
	}
}

/**
 *
 * @param arg
 */
void* Server::connectionManager(void* arg)
{
	pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;

	int socket = *(int*)arg;
	int read_size;

	char* message;
	char buffer[256];

	message = "Soy su manejador\n";

	write(socket, message, strlen(message));

	//(read_size = recv(socket , mensaje_cliente , 2000 , 0)) >0
	while(true)
	{
		pthread_mutex_lock(&mutex);
		sleep(0.2);
		bzero(buffer,256);

		read_size = read(socket, buffer, 256);
		string client_message = string(buffer);

		if(read_size > 0)
		{
			//cout << mensaje << endl;
			messages_list->insertData(client_message);
		}

		if(client_message.compare("CLOSE") == 2)
		{
			cout << "Se desconectó el cliente" << endl;
			fflush(stdout);
			pthread_exit(NULL);
			break;
		}

		if(read_size == -1)
		{
			std::cout << "Error al hacer la lectura" << std::endl;
		}
//		messages_list->showList();
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

string Server::getPrimerMensaje()
{
	pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_lock(&mutex);
	if(messages_list->getLen()==0){
		pthread_mutex_unlock(&mutex);
		return "-1";
	}
	string ans = messages_list->getHead()->getData();
	messages_list->deleteData(ans);
	pthread_mutex_unlock(&mutex);
	return ans;
}
