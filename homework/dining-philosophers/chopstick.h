/**
 * Public definitions for a chopstick.
 */
#ifndef __CHOPSTICK__
#define __CHOPSTICK__

typedef int chopstick;

#define CHOPSTICK_COUNT 5
#define ITEM_BOUND 10

/**
 * Number of characters needed to display an item; it's essentially
 * ceil(log10(ITEM_BOUND)).
 */
#define ITEM_WIDTH 1

#endif
