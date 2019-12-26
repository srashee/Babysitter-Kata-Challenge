#include <stdio.h>
#include "babysitter.h"

int babysitter(char familyType, int startTime, int endTime) {
    int total = 0;
    size_t startTime2 = 0;
    size_t endTime2 = 0;

    /* Validate the start time */
    if ((startTime >= 17 && startTime <= 24) ||
            (startTime >= 0 && startTime <= 4 )) {
    }
    else {
#ifdef DEBUG
        printf("Invalid Start Time given \n");
#endif
        return INVALID_START;
    }

    /* Validate the end time */
    if ((endTime <= 4 && endTime >= 0) ||
            (endTime >= 17 && endTime <= 24)) {
    }
    else {
#ifdef DEBUG
        printf("Invalid End time given \n");
#endif
        return INVALID_END;
    }

    /* To make computation easier we will recalibrate how we see
     * these numbers since we no longer need to worry about input
     * validation
     * Current Range
     * 17 - 24 - 4
     * New Range
     * 0 - 11  (0 Signifies 5PM, 11 signifies 4AM) */
    if (startTime < 4)
        startTime2 = startTime + 7;
    else
        startTime2 = startTime - 17;

    if (endTime <= 4)
        endTime2 = endTime + 7;
    else
        endTime2 = endTime - 17;


    switch (familyType) {
        case 'a':
        case 'A':
            /* 11PM is 6 on new range */
            /* If we started before 11PM */
            if (startTime2 < 6) {
                /* If we ended before 11PM */
                if (endTime2 <= 6) {
                    total = ((endTime2 - startTime2) * 15);
                }
                /* If we didn't end before 11PM */
                else {
                    total = ((6 - startTime2) * 15);
                    total += ((endTime2 - 6) * 20);
                }
            }
            /* If we didn't start before 11PM */
            else
                total = ((endTime2 - startTime2) * 20);
            break;


        default:
            /* Invalid Parameter Given */
#ifdef DEBUG
            printf("Invalid parameter given\n");
#endif // DEBUG
            total = INVALID_FAMILY;
        }
        printf("Total is %d\n", total);
        return total;
    }
