//implementation of proccess sync using mutex

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

int shared = 1;
pthread_mutex_t m;

void* fun1() {
    printf("\ninside fun 1 : b4 lock");
	pthread_mutex_lock(&m);
	printf("\ninside fun 1 : Locked");
	int x = shared;
	printf("\nInside fun 1: %d \n", x);
	printf("\nlocal value inc fun 1 : %d\n",++x);
	sleep(1);
	shared = x;
	printf("\nvalue updated fun 1: %d\n", shared);
    printf("\ninside fun 1 : b4 unlock");
	pthread_mutex_unlock(&m);
    printf("\ninside fun 1 : Unlocked");

}

void* fun2() {
    printf("\ninside fun 2 : b4 lock");
	pthread_mutex_lock(&m);
    printf("\ninside fun 2 : Locked");
	int x = shared;
	printf("\nInside fun 2: %d \n", x);
	printf("\nlocal value inc fun 2 : %d\n",--x);
	sleep(1);
	shared = x;
	printf("\nvalue updated fun 2: %d\n", shared);
    printf("\ninside fun 2 : b4 unlock");
	pthread_mutex_unlock(&m);
    printf("\ninside fun 2 : Unlocked");

}

int main() {

    pthread_t thread1, thread2;
    int ret1, ret2;
    
    pthread_mutex_init(&m, NULL);	
    ret1 = pthread_create(&thread1, NULL, fun1, NULL);
    ret2 = pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nThe shared no : %d\n", shared);
    return 0;
}
