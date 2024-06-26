#include<stdio.h>
#include<unistd.h>
// #include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

int shared = 1;

void* fun1() {
	int x = shared;
	printf("Inside fun : %d \n", x);
	printf("local value inc : %d\n",++x);
	sleep(1);
	shared = x;
	printf("value updated fin 1: %d\n", shared);
}

void* fun2() {
	int x = shared;
	printf("Inside fun : %d \n", x);
	printf("local value dec : %d\n",--x);
	sleep(1);
	shared = x;
	printf("value updated fin 1: %d\n", shared);
}

int main() {

    pthread_t thread1, thread2;
    int ret1, ret2;

    ret1 = pthread_create(&thread1, NULL, fun1, NULL);
    ret2 = pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("The shared no : %d", shared);
    return 0;
}
	





