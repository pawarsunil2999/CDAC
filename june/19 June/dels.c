#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>


#define PORT 8080

int main() {
	
	int server_fd, new_socket;
	int opt = 1;

	char buffer[1024024] = {0};
	char *hello = "hello";

	struct sockaddr_in address;
	int addrlen = sizeof(address);

	if( (server_fd = socket(AF_INET, SOCK_STREAM, 0 )) < 0 ) {
		exit(1);
	}

	if( setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt) ) < 0 ) {
		exit(1);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if( bind( server_fd, (struct sockaddr*)&address, sizeof(address))  < 0 ) {
		printf("erroe");
		exit(1);
	}

	if(listen(server_fd, 3) < 0) {
		printf("socket error");
		exit(1);
	}

	if( (new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
		exit(1);
	}
	
	read(server_fd, buffer, 1024);
	printf("%s", buffer);
	send(server_fd, hello, strlen(hello), 0 );

	return 0;


}


