#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* pthreads() {
	for( int i=0; i<5; i++ ) {
		printf("\nInside thread : %d", i+1);
		sleep(1);
		
	}
}

int main() {
	
	pthread_t thread;

	pthread_create( &thread,NULL,  pthreads, NULL );
//	pthread_join(thread, NULL);


	for( int i=0; i<5; i++ ) {
		printf("\nInside Process : %d", i+1);
		sleep(1);
	}


}
