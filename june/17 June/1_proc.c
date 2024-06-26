//implementation of inter proccess comunication

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
	
	pid_t p;

	p = fork();

	if( p < 0 ) {
			printf("\nError in the process\n");
			exit(1);
		}
	else if( p == 0 ) {

		for(int i=0; i<3; i++ ) {
			printf( "\nChild Process %d: %d", getpid(), i+1);
		}

		int p = fork();

		if( p<0 ) {
			printf("\nError in nested child process");
			exit(1);
		}
		else if( p > 0) {
			for(int i=0; i<3; i++) {
				printf("\nNested parent process %d: %d", getppid(), i+1);
			}
		}
		else {
			for(int i=0; i<3; i++ ) {
				printf("\nNested child Process %d: %d", getpid(), i+1);
			}
		}	

	}
	else if(p > 0) {
		for( int i=0; i<3; i++ ) {
			printf( "\nparent process %d: %d", getppid(), i+1);
		}
	}
	
	int count=0;
	printf("\nThis isnt forked : %d", ++count);


//printf("Child : %d\nparent :%d\np: %d", getpid(), getppid(), p);














 




 

 
 


















}

