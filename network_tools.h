#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define LOG
#include "log.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 256
#endif

#ifndef CON_MAX_ATTEMPTS
#define CON_MAX_ATTEMPTS 5
#endif

int send_data(int sockfd, const char *msg){
	int sent_bytes = 0;
	if (sent_bytes = write (sockfd, msg, BUFFER_SIZE) < 0){
		logger("sending failed")(PERROR);
		return -1;
	}
	logger("sent data: %s", msg)(INFO);
	return sent_bytes;
}

char *recv_data (int sockfd){
	char *buffer = (char *)malloc(BUFFER_SIZE);
	if (read (sockfd, buffer, BUFFER_SIZE) < 0){
		logger("read failed")(PERROR);
		return NULL;
	}
	logger("data received: %s", buffer)(INFO);
	return buffer;
}

int disconnect_server(int sockfd){
	if(close(sockfd) == -1){
		logger("Disconnection Unsuccesful")(PERROR);
	}
	else logger("Disconnection Successful")(INFO);
}

int connect_server (const char * hostname, int port, int DOMAIN, int TYPE){
	struct sockaddr_in serv_addr;
	struct hostent *server;
	//checking whether port is between 0 and 65536
	if (port < 0 || port > 65535){
		logger ("invalid port number, port number should be between 0 and 65536")(ERROR);
		return -1;
	}
	//Create socket
	int sockfd = socket(DOMAIN , TYPE , 0);
	if (sockfd == -1){
		logger("Could not create socket")(ERROR);
		return -1;
	}
	logger("Socket created")(INFO);
	if((server = gethostbyname(hostname))==NULL){
		logger("no such host found")(ERROR);
		return -1;
	}
	memset((char *)&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	memcpy((char*)&serv_addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
	serv_addr.sin_port = htons( port );
	int i = 0;
	while (connect (sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1){
		if(i++ > CON_MAX_ATTEMPTS){
			//guess other hostnames for the user
			close(sockfd);
			logger("cannot establish connection to %s on port %d", hostname, port)(PERROR);
			return -1;
		}
	}
	logger("connection established successfully to %s on port %d", hostname, port)(INFO);
	return sockfd;
}

#ifndef SERV_BACKLOG
#define SERV_BACKLOG 10
#endif

int start_server(int port){
	//Create socket
	int servfd = socket(PF_INET , SOCK_STREAM , 0);
	if (servfd == -1){
		logger("could not create socket")(PERROR);
		return -1;
	}

	struct sockaddr_in server, client;
    	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( port );
	//Bind
	if( bind(servfd,(struct sockaddr *)&server , sizeof(server)) < 0){
		logger("bind failed")(PERROR);
		return -1;
	}
	//Listen
	listen(servfd , SERV_BACKLOG);
	//Accept and incoming connection
	logger("Waiting for incoming connections...")(INFO);
	//accept connection from an incoming client
	socklen_t cli_size = sizeof(struct sockaddr_in);
	int clifd = accept(servfd, (struct sockaddr *)&client, &cli_size);
	if (clifd < 0){
		logger("Accept failed")(PERROR);
		return -1;
	}
	logger("Connection accepted")(INFO);
	return clifd;
}
#endif
