//client server communicatoin
//socket programing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    
    int client_fd = 0, size;
    
    char *hello = "Hello from client";
    char str[1024] = {0};
    
    //struct sockaddr_in address;
    struct sockaddr_in serv_addr;

    if (( client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address \n");
        return -1;
    }

    if (connect( client_fd , (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    send( client_fd, hello, strlen(hello), 0);
    printf("Hello msg sent\n");
    size = read( client_fd, str, 1024);
    printf("Server: %s\n", str);
    return 0;
}

