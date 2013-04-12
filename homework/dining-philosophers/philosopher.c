/**
 * Philospher implementation: Philopsoher with Right Chopstick chopstickRight and Left Chopstick chopstickRight + 1
 */
#include "dp-cs.h"
#include "dp-sync.h"
#include "chopstick.h"
#include "utility.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

static char chopsticksName[] = {'A', 'B', 'C', 'D', 'E'};
static char *philosopherName[] = {"Kant", "Heidegger", "Socrates", "Beauvoir", "Descartes"};
static pthread_mutex_t * chopsticksMutex[] = { &cA, &cB, &cC, &cD, &cE};

void philosopher(int chopstickRight) {
    char *name = philosopherName[chopstickRight];

    pthread_mutex_t *chopstickRightM = chopsticksMutex[chopstickRight];
    pthread_mutex_t *chopstickLeftM = chopsticksMutex[(chopstickRight + 1) % 5];

    char right = chopsticksName[chopstickRight];
    char left = chopsticksName[(chopstickRight + 1) % 5];

    while(1) {
        int consumeBound = (rand() % 10) +1; // generates random wait time every cycle. 
        randomwait(consumeBound); //thinking

        pthread_mutex_lock(chopstickRightM);
        printf("Chopstick %c is now taken by %s!\n", right, name);
        pthread_mutex_lock(chopstickLeftM);
        printf("Chopstick %c is now taken by %s!\n", left, name);

        if (get_chopstick(chopstickRight)) {
            fprintf(stderr, "***** Could not get chopstick on right, %c !\n", right);
            pthread_mutex_unlock(chopstickRightM);
            return;
        }
        if (get_chopstick((chopstickRight + 1) % 5)) {
            fprintf(stderr, "***** Could not get chopstick on left, %c !\n", left);
            pthread_mutex_unlock(chopstickLeftM);
            return;
        }

        printf("%s has began to eat!\n", name );
        randomwait(consumeBound); //eating
        printf("%s has finished eating! \n", name);

        if (drop_chopstick(chopstickRight)) {
            fprintf(stderr, "***** Could not drop chopstick on right, %c !\n", right);
            pthread_mutex_unlock(chopstickRightM);
            return;
        }
        if (drop_chopstick((chopstickRight + 1) % 5)) {
            fprintf(stderr, "***** Could not drop chopstick on left, %c !\n", left);
            pthread_mutex_unlock(chopstickLeftM);
            return;
        }

        pthread_mutex_unlock(chopstickRightM);
        printf("Chopstick %c is now Available!\n", right);
        pthread_mutex_unlock(chopstickLeftM);
        printf("Chopstick %c is now Available!\n", left);
    }
}


