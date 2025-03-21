#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_ALLOCATIONS 1000

void *thread_function(void *arg) {
    int thread_id = *(int *)arg;
    printf("Thread %d started\n", thread_id);

    for (int i = 0; i < NUM_ALLOCATIONS; i++) {
        void *ptr = malloc(128);  // Allocate 128 bytes
        if (!ptr) {
            fprintf(stderr, "Thread %d: malloc failed!\n", thread_id);
            pthread_exit(NULL);
        }
        free(ptr);  // Free the allocated memory
    }

    printf("Thread %d finished\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    printf("Starting multithreaded malloc test...\n");

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Multithreaded malloc test completed successfully!\n");

    return 0;
}
