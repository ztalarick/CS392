//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include "cs392_log.h"
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_PENDING 5

int main(int argc, char** argv){
	int sockfd, clientfd;
	struct sockaddr_in serv_addr, client_addr;
	char buffer[256];
	int n;

	if(argc != 2){
		perror("Usage: ./cs392_echoserver <port>\n");
		exit(EXIT_FAILURE);
	}

	 if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){ //create socket
		perror("Error opening socket\n");
		exit(EXIT_FAILURE);
	}

	//bzero((char *)&serv_addr, sizeof(serv_addr)); //intialize serv_addr struct
	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;	
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1])); 	//port num

	if( (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0){ //bind
		perror("Error binding\n");
		exit(EXIT_FAILURE);
	} 
	listen(sockfd, MAX_PENDING); //listen for connections

	while(1){
		
		int clientlen = sizeof(client_addr);
		if( (clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen)) < 0){ //accept connection
			perror("Error accepting\n");
			exit(EXIT_FAILURE);
		}
		
		cs392_socket_log(inet_ntoa(client_addr.sin_addr), argv[1]);

		recv(clientfd, buffer, 256, 0);
		send(clientfd, buffer, 256, 0); 
		
		close(clientfd);
	}

	exit(EXIT_SUCCESS);
}
