#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket){
	char buffer[BUFFER_SIZE] = {0};
	char filename[BUFFER_SIZE] = {0};

	//receive filename
	int bytes_received = recv(client_socket, filename, BUFFER_SIZE, 0);
	if(bytes_received < 0){
		perror("error receiving filename");
		close(client_socket);
	}

	//open requested file
	FILE *file = fopen(filename, "r");
	if(file == NULL){
		char *error_message = "File not found! \n");
		send(client_socket, error_message, strlen(error_message), 0);
		perror("file not found! \n");
	} else {
		//read file and send content
		while(fgets(buffer, BUFFER_SIZE, file) != NULL){
			send(client_socket, buffer, strlen(buffer), 0);
			memset(buffer, 0, BUFFER_SIZE);
		}
		printf("File is being sent to client \n");
		fclose(file);
	}
	close(client_socket);
}

int main(){
	int server_socket, client_socket;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_len = sizeof(client_addr);

	//create server socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(server_socket == 0){
		perror("socket creation failed! \n");
		exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);

	//bind socket
	if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
		perror("bind failed! \n");
		exit(EXIT_FAILURE);
	}

	//start listening
	printf("LISTENING on port %d!", PORT);
	listen(server_socket, 3);

	while(1){
		client_socket =  connect(server_socket, (struct sockaddr *)&client_addr, addr_len);
		if(client_socket < 0){
			perror("Accept failed!\n");
			exit(EXIT_FAILURE);
		}
		printf("client connected");
		
		//handle client
		handle_client(client_socket);
	}
	close(server_socket);
	return 0;
}
