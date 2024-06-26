#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

int shared = 1;
sem_t s;

void* fun1() {
    printf("\ninside fun 1 : b4 lock");
	sem_wait(&s);
    printf("\ninside fun 1 : Locked");
	int x = shared;
	printf("\nInside fun 1: %d \n", x);
	printf("\nlocal value inc fun 1 : %d\n",++x);
	sleep(1);
	shared = x;
	printf("\nvalue updated fun 1: %d\n", shared);
    printf("\ninside fun 1 : b4 unlock");
	sem_post(&s);
    printf("\ninside fun 1 : Unlocked");

}

void* fun2() {
    printf("\ninside fun 2 : b4 lock");
	sem_wait(&s);
    printf("\ninside fun 2 : Locked");
	int x = shared;
	printf("\nInside fun 2: %d \n", x);
	printf("\nlocal value inc fun 2 : %d\n",--x);
	sleep(1);
	shared = x;
	printf("\nvalue updated fun 2: %d\n", shared);
    printf("\ninside fun 2 : b4 unlock");
	sem_post(&s);
    printf("\ninside fun 2 : Unlocked");

}

int main() {

    sem_init( &s, 0, 1);
    pthread_t thread1, thread2;
    int ret1, ret2;

   
    
    ret1 = pthread_create(&thread1, NULL, fun1, NULL);
    ret2 = pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nThe shared no : %d\n", shared);
    return 0;
}
	





