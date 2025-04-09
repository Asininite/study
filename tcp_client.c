#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(){
	int sockfd;
	struct sockaddr_in server;
	char buffer[BUFFER_SIZE];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(PORT);

	connect(sockfd, (struct sockaddr *)&server, sizeof(server));
	send(sockfd, buffer, strlen(buffer), 0);
	read(sockfd, buffer, sizeof(buffer));
	printf("Response %s \n", buffer);
	close(sockfd);

	return 0;
}
