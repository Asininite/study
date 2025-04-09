#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
	int sockfd, newsock;
	struct sockaddr_in server, client;
	socklen_t len = sizeof(client);
	char buffer[BUFFER_SIZE];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	bind(sockfd, (struct sockaddr *)&server, sizeof(server));
	listen(sockfd, 5);
	printf("waiting for connection");

	newsock = accept(sockfd, (struct sockaddr *)&client, &len);
	read(newsock, buffer, sizeof(buffer));
	printf("Message : %s \n", buffer);

	send(newsock, "hello", 5, 0);
	close(newsock);
	close(sockfd);

	return 0;
	
}
