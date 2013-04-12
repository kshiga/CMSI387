/**
 * Definitions for critical-section functions and shared resources.
 */
#ifndef __DP_CS__
#define __DP_CS__

#include "chopstick.h"

/**
 * Gets the chopstick.
 */
int get_chopstick(chopstick chopstick);

/**
 * Puts down the chopstick.
 */
int drop_chopstick(chopstick chopstick);
    
#endif
