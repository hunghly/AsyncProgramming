#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int data_ready = 0;

// produces
void* producer(void *arg) {
    pthread_mutex_lock(&lock);
    data_ready = 1; // set condition
    printf("Producer data is ready. Signalling consumer...\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* consumer(void* arg) {
    pthread_mutex_lock(&lock);
    while (data_ready == 0) {  // Wait until the condition is true
        printf("Consumer: Waiting for data...\n");
        pthread_cond_wait(&cond, &lock);  // Releases lock and waits
    }
    printf("Consumer: Got the data!\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {

    pthread_t t1, t2;
    pthread_create(&t1, NULL, consumer, NULL);
    pthread_create(&t2, NULL, producer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    return 0;
}