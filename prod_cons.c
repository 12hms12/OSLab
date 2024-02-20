#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

#define MAX 100

int buff[MAX];
sem_t pmutex, cmutex, empty, full;
int in = 0, out = 0;
int item = 0;

void *produce(void *);
void *consume(void *);

void *produce(void *arg) {

        sem_wait(&empty);
        sem_wait(&pmutex);

        item++;
        buff[in] = item;
        printf("Produced Data %d\n", buff[in]);
        in = (in + 1) % MAX;

        sem_post(&pmutex);
        sem_post(&full);

}

void *consume(void *arg) {

        sem_wait(&full);
        sem_wait(&cmutex);

        int citem = buff[out];
        printf("Consumed Data %d\n", citem);
        out = (out + 1) % MAX;

        sem_post(&cmutex);
        sem_post(&empty);

}

int main(int argc, const char * argv[]) {
    sem_init(&pmutex, 0, 1);
    sem_init(&cmutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, MAX);

    pthread_t producer, consumer;

    pthread_create(&producer, NULL, produce, NULL);
    pthread_create(&consumer, NULL, consume, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    return 0;
}
