/**
 * Synchronization primitive implementation.
 */
#include "dp-sync.h"

#include "chopsticks.h"

#include <pthread.h>
#include <semaphore.h>

void initSync(void) {
    pthread_mutex_init(&cA, NULL);
    pthread_mutex_init(&cB, NULL);
    pthread_mutex_init(&cC, NULL);
    pthread_mutex_init(&cD, NULL);
    pthread_mutex_init(&cE, NULL);
}
