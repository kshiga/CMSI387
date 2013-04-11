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

void eat(const char * philospherName, int chopstickRight){
    const char * name = philosopherName;
    int consumeBound = Math.Random;
    pthread_mutex_t chopstickRightM = chopsticksMutex[chopstickRight];
    pthread_mutex_t chopstickLeftM = chopsticksMutex[(chopstickRight + 1) % 5];
    const char * right = chopsticksName[chopstickRight];
    const char * left = chopsticksName[(chopstickRight + 1) % 5];


    while(1) {
        pthread_mutex_lock(&chopstickRightM);
        printf("Chopstick %s is now taken by %s!\n", right, philosopherName);
        pthread_mutex_lock(&chopstickRightL);
        printf("Chopstick %s is now taken by %s!\n", left, philosopherName);

        if (get_chopstick(chopstickRight)) {
            fprintf(stderr, "***** Could not get chopstick on right, %s !\n", right);
            pthread_mutex_unlock(&chopstickRightM);
            return;
        }

        if (get_chopstick((chopstickRight+1))) {
            fprintf(stderr, "***** Could not get chopstick on left, %s !\n", left);
            pthread_mutex_unlock(&chopstickLeftM);
            return;
        }

        printf("%s has began to eat!\n", philosopherName );
        randomwait(consumeBound);
        printf("%s has finished eating! \n", philosopherName);

        if (drop_chopstick(chopstickRight)) {
            fprintf(stderr, "***** Could not drop chopstick on right, %s !\n", right);
            pthread_mutex_unlock(&chopstickRightM);
            return;
        }

        if (drop_chopstick((chopstickRight+1)) {
            fprintf(stderr, "***** Could not drop chopstick on left, %s !\n", left);
            pthread_mutex_unlock(&chopstickLeftM);
            return;
        }

        pthread_mutex_unlock(&chopstickRightM);
        printf("Chopstick C is now Available!\n");
        pthread_mutex_unlock(&chopstickLeftM);
        printf("Chopstick D is now Available!\n");

    }
    randomwait(consumeBound);
}


