#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* threading( void* num1 ) {
	int* num =( int*)num1;
	int* result = malloc( sizeof(int));
	*result = num[0] + num[1];
	pthread_exit(result);
}

int main() {
	int ret1;
	int arr[] = {2,3};
	int* result;
	pthread_t thread;
	int rtn = pthread_create(&thread, NULL, threading, (void*)arr);
	pthread_join(thread, (void**)&result);
	
	printf("\nThe sum of : %d", *result);
}
