/**
 * Implementation of the software paging unit.
 */
#include "addressTranslation.h"

#include <stdio.h>
#include <stdlib.h>

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {
    // JD: In terms of spacing, you should put a space after
    //     the if and before the opening curly brace:
    //
    // if ((logical < 0) || (logical > 255)) {
    if((logical < 0) || (logical > 255)){
        return ERR_OUT_OF_RANGE;
    }

    // JD: This is right, but better to use the PAGESIZE,
    //     PAGEBITS, and PAGEMASK macros defined in the .h
    //     file---if you do it that way, changing those
    //     will automatically adapt your code to different
    //     address register and page size settings.
    int offset = logical & 0xF;
    int page = (logical & 0xF0) >> 4;
    pagetable workingPT = ptr[page];
    int valid = workingPT.valid;

    if(!(valid)){
        return ERR_INVALID;
    }

    int frame = workingPT.frame << 4;
    int address = (frame ^ offset);

    return address;
}
