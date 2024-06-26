#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* threading() {
	for( int i=0; i<5; i++) {
		printf("\nThread %d", i+1);
		sleep(1);
	}
}


int main() {

	pthread_t thread1, thread2;
	pthread_create( &thread1, NULL, threading, NULL);
	//pthread_join(thread1, NULL);

	for( int i=10; i<15; i++) {
                printf("\nMain : %d", i+1);
                sleep(1);
        }


}
