#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h> 
#include <stdlib.h> 

int main() {

    int fd[2];
    pid_t p;
    char str[100], destStr[100];

    if (pipe(fd) == -1) {
    	printf("pipe failed");
        return 1;
    }

    p = fork();

    if (p > 0) { 
        close(fd[0]); 
        printf("\nEnter the msg to p2: ");
        scanf("%s", str);
        write(fd[1], str, sizeof(str)); 
        close(fd[1]); 
    }
    else if (p == 0) { 
        close(fd[1]); 
        int n = read(fd[0], destStr, sizeof(destStr)); 
        destStr[n] = '\0';
        printf("\nChild received msg: %s\n", destStr);
        close(fd[0]); 
    }
    else {
        perror("fork failed");
    }

    return 0;
}

