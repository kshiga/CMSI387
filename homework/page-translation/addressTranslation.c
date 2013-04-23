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
    if((logical < 0) || (logical > 255)){
        return ERR_OUT_OF_RANGE;
    }

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
