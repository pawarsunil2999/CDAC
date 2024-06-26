#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket failed");
    }
    
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error("setsockopt");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("bind failed");
    }
    if (listen(server_fd, 3) < 0) {
        error("listen");
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        error("accept");
    }

    while (1) {
        // Clear the buffers
        memset(buffer, 0, BUFFER_SIZE);
        memset(message, 0, BUFFER_SIZE);

        // Read client message
        valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0)
            break;
        printf("Client: %s\n", buffer);

        // Prepare server response
        printf("Server: ");
        fgets(message, BUFFER_SIZE, stdin);

        // Send response to the client
        send(new_socket, message, strlen(message), 0);
        printf("Message sent\n");
    }

    // Close the socket
    close(new_socket);
    close(server_fd);
    return 0;
}

