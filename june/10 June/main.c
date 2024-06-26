//IMPLEMENTATION OF fork() FUNCTION

#include <signal.h>
       #include <stdint.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
int main() {
	
	pid_t p;
	p = fork();
	int i = 5;
	if( p == 0 ) {
		while( i )
			printf("\nchild : %d", i--);
	}
	else if( p > 0 ) {
		while( i )
			printf("\nParent : %d", i--);
	}
	else { 
		printf("\nError occured");
	}
	
	printf("\nCommon : %d", i);
	
	return 0;
}
