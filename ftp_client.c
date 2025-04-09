#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
	int client_socket;
	struct sockaddr_in server_addr;
	char buffer[BUFFER_SIZE] = {0};
	char filename[BUFFER_SIZE] = {0};

	//create client socket
	client_socket = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");;
	server_addr.sin_port = htons(PORT);

	connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

	//get filename from user
	printf("Enter the name of the file to fetch");
	scanf("%s", filename);

	//send filename to server
	send(client_socket, filename, strlen(filename), 0);

	//receive and print file content
	printf("File content received");
	while(recv(client_socket, buffer, BUFFER_SIZE,0) > 0){
		printf("%s", buffer);
		memset(buffer,0,BUFFER_SIZE);
	}

	printf("\n");
	close(client_socket);
	return 0;
}
