//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv){
	if(argc != 3){
		perror("Usage: ./cs392client <IP> <PORT>");
		exit(EXIT_FAILURE);
	}
	int sock; 
	struct sockaddr_in echoserver;

	char buffer[256]; unsigned int echolen; int received = 0;

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sock < 0){
		perror("Error client socket");
		exit(EXIT_FAILURE);
	}

	memset(&echoserver, 0, sizeof(echoserver)); /* Clear struct */

	echoserver.sin_family = AF_INET; /* Internet/IP */

	echoserver.sin_addr.s_addr = inet_addr(argv[1]); /* IP address */

	echoserver.sin_port = htons(atoi(argv[2])); /* server port */

	if(connect(sock, (struct sockaddr *) &echoserver, sizeof(echoserver)) < 0){
		perror("Error client connect");
		exit(EXIT_FAILURE);
	}

	printf("Enter text to send to the server: ");
	fflush(stdout);
	
	
	fgets(buffer, 256, stdin);


	if(send(sock, buffer, 256, 0) < 0){
		perror("Error client send");
		exit(EXIT_FAILURE);
	}
	
	char response[256];
	if(recv(sock, response, 256, 0) < 0){
		perror("Error client recv");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", response);

	exit(EXIT_SUCCESS);
}
