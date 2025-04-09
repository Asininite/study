#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
	int sockfd;
	struct sockaddr_in server, client;
	socklen_t len = sizeof(client);
	char buffer[1024];

	//create UDP socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	//server address config
	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = INADDR_ANY;

	//binding the socket to server address
	bind(sockfd, (struct sockaddr *)&server, sizeof(server));
	
	printf("waiting for data from client");

	recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &len);
	printf("Message from client %s \n", buffer);
	
	//respond to client
	sendto(sockfd, "hello from server", 18, 0, (struct sockaddr *)&client, len);

	close(sockfd);
	return 0;
}


