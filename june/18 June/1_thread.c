#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to be executed by the first thread
void* print_message_function(void* ptr) {
    char* message = (char*)ptr;
    for(int i = 0; i < 5; i++) {
        printf("%s\n", message);
        sleep(1); // Sleep for 1 second
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    char message1[] = "Thread 1";
    char message2[] = "Thread 2";
    int ret1, ret2;

    // Create threads
    ret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    ret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);

    // Check for errors in thread creation
    if (ret1) {
        printf("Error in the thread :  %d\n", ret1);
        exit(1);
    }
    if (ret2) {
        printf("Error in the thread :  %d\n", ret2);
        exit(1);
    }

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Threads finished executing.\n");

    return 0;
}

