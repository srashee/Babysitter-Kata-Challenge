#include <stdio.h>
#include "babysitter.h"

int babysitter(char familyType, int startTime, int endTime) {

    /* Validate the start time */
    if ((startTime >= 17 && startTime <= 24) ||
            (startTime >= 0 && startTime <= 4 )) {
    }
    else {
        printf("Invalid Start Time given \n");
        return INVALID_START;
    }

    /* Validate the end time */
    if ((endTime <= 4 && endTime >= 0) ||
            (endTime >= 17 && endTime <= 24)) {
    }
    else {
        printf("Invalid End time given \n");
        return INVALID_END;
    }

        return 0;
}
