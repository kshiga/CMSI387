/**
 * Implementation (and privates) for critical-section functions.
 */
#include "dp-cs.h"
#include "chopstick.h"

#include <stdio.h>
#include <string.h>


static chopstick table[CHOPSTICK_COUNT] = {1, 1, 1, 1, 1};

void display_table(const char *chopstickAction, int avaliable, int chopstickCurrent) {
    char display[CHOPSTICK_COUNT * (ITEM_WIDTH + 1) + 64]; //display
    char chopstick[ITEM_WIDTH + 1];//individual item to be displayed
    sprintf(display, "%s chopstick at position %d [ ", chopstickAction, chopstickCurrent);
    int i;
    for (i = 0; i < CHOPSTICK_COUNT; i++) {
        sprintf(chopstick, "%d ", table[i]);

        if (i == chopstickCurrent && !avaliable) {
            strcat(display, "! taking >");
        } else if (i == chopstickCurrent && avaliable){
            strcat(display, "! dropping >");
        }
        strcat(display, chopstick);
    }
    strcat(display, "]\n");
    printf("%s", display);

}


int get_chopstick(chopstick chopstick) {
    const char *chopstickAction = "took";
    if(table[chopstick] == 0){
        printf("*** CRITICAL SECTION VIOLATION ***\n");
        printf("*** THIS CHOPSTICK IS NOT ON THE TABLE ***\n");
        return -1;
    }    
    table[chopstick] = 0;
    display_table(chopstickAction, 0, chopstick);

    return 0;
}

int drop_chopstick(chopstick chopstick){
    const char *chopstickAction = "put back";
    if(table[chopstick] == 1){
        printf("*** CRITICAL SECTION VIOLATION ***\n");
        printf("*** THIS CHOPSTICK IS ALREADY ON THE TABLE ***\n");
        return -1;
    }
    table[chopstick] = 1;   
    display_table(chopstickAction, 1, chopstick);
      
    return 0;
}

