/**
 * Synchronization elements for a dining philosophers solution.
 */
#ifndef __DP_SYNC__
#define __DP_SYNC__

#include <pthread.h>
#include <semaphore.h>

/**
* Locks for each individual chopstick
*/
pthread_mutex_t chopsticksMutex = {cA, cB, cC, cD, cE};

const char * chopsticksName["A", "B", "C", "D", "E"];

/**
 * Initializes synchronization primitives.
 */
void initSync(void);

#endif
