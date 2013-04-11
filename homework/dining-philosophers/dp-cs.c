/**
 * Implementation (and privates) for critical-section functions.
 */
#include "dp-cs.h"
#include "chopstick.h"

#include <stdio.h>
#include <string.h>

static int avaliable = 1;
static int taken = 0;
static int table[CHOPSTICK_COUNT];

void display_table(const char *chopstickAction, int taking, int chopstickName) {
    char display[CHOPSTICK_COUNT]

}


void display_buffer(const char *preface, int in, int out) {
    char display[BUFFER_SIZE * (ITEM_WIDTH + 1) + 64];
    char buffer_content[ITEM_WIDTH + 1];
    sprintf(display, "(%s) in: %d out: %d [ ", preface, in, out);
    int i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        sprintf(buffer_content, "%d", buffer[i]);

        if (i == in) {
            strcat(display, "+>");
        }
        strcat(display, buffer_content);

        if (i == out) {
            strcat(display, "->");
        }
        strcat(display, " ");
    }
    strcat(display, "]\n");
    printf("%s", display);
}


int get_chopstick(int chopstick){
    const char * chopstickAction = "took";
    if(table[chopstick] == taken){
        printf("*** CRITICAL SECTION VIOLATION ***\n");
        printf("*** THIS CHOPSTICK IS NOT ON THE TABLE ***\n");
        return -1;
    }    
    table[chopstick] = taken;
    display_table(chopstickAction, taken, chopstick);

    return 0;
}

int drop_chopstick(int chopstick){
    const char * chopstickAction = "put back";
    if(table[chopstick] == avaliable){
        printf("*** CRITICAL SECTION VIOLATION ***\n");
        printf("*** THIS CHOPSTICK IS ALREADY ON THE TABLE ***\n");
        return -1;
    }
    table[chopstick] = available;   
    display_table(chopstickAction, avaliable, chopstick);
      
    return 0;
}

