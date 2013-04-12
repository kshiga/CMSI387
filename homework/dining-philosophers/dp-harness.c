/**
 * A test harness for running solutions to the dining philospher problem.
 */
#include <pthread.h>
#include <stdio.h>

#include "dp-sync.h"

void *philosopher(int chopstickRight);

/**
 * Thread runner for the philosopher.
 */
void *philospherRunner(void *arg) {
    philosopher((int)arg);
    printf("philsopher Activated!\n");
    pthread_exit(NULL);
}
/**
 * Overall driver program.
 */
int main(int argc, char** argv) {
    printf("Starting dining philosopher test harness...\n");

    /* Initialize the synchronization primitives. */
    initSync();

    /* Start the threads. */
    pthread_t kant, heidegger, socrates, beauvoir, descartes;
    pthread_create(&kant, NULL, philospherRunner, (void *)0);
    pthread_create(&heidegger, NULL, philospherRunner, (void *)1);
    pthread_create(&socrates, NULL, philospherRunner, (void *)2);
    pthread_create(&beauvoir, NULL, philospherRunner, (void *)3);
    pthread_create(&descartes, NULL, philospherRunner, (void *)4);


    /* Not really needed, since we'll pretty much run forever... */
    pthread_join(kant, NULL);
    pthread_join(heidegger, NULL);
    pthread_join(socrates, NULL);
    pthread_join(beauvoir, NULL);
    pthread_join(descartes, NULL);

    /* We won't really get here, but to avoid any warnings... */
    return 0;
}
