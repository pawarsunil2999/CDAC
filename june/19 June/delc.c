#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

int main() {
	int client_fd, size;
	
	char buffer[100] = {0};
	char *hello = "hello from client\n";
	
	struct sockaddr_in address;
	
	if( (client_fd = socket(AF_INET, SOCK_STREAM< 0)) < 0) {
		printf("error");
		exit(1);
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if( connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0 ) {
		printf("error");
		exit(1);
	}	
	
	send(client_fd, hello, strlen(hello), 0);
	printf("");
	size = read(client_fd, buffer, sizeof(buffer));
	
	
}
