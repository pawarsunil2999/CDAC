//creation of pipe to communicate between two processes

#include<stdio.h>
#include<unistd.h>
//#include<sys/type.h>

int main() {
	
	int fd[2], n;
	char str[100], destStr[100];
	pid_t p = fork();
	
	if( p>0 ) {//parent process
		printf("\nEnter the msg to p2 : ");
		scanf("%s", str);
		write(fd[1], str, 100);
	}
	else if(p==0) {//child
		printf("\nchild recieved msg : ");
		int n = read(fd[0], destStr, 100);
		read(0, destStr, n );
	}
	else {
		printf("\nfile not opned");
	}

	close(0);
	return 0;
		
}
