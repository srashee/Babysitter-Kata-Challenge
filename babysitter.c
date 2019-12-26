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

        case 'b':
        case 'B':
            /* 10PM is 5 on new range */
            /* If we started before 10PM */
            if (startTime2 < 5) {
                /* If we ended before 10PM */
                if (endTime2 <= 5) {
                    total = ((endTime2 - startTime2) * 12);
                }
                /* Or if we ended before 12PM */
                else if(endTime2 <= 7) {
                    total = ((5 - startTime2) * 12);
                    total += ((7 - endTime2) * 8);
                }
                /* If we didn't end before 12 PM */
                else {
                    total = ((5 - startTime2) * 12);
                    total += ((7 - 5) * 8);
                    total += ((endTime2 - 7) * 16);
                }
            }
            /* Or if we started before 12PM but not before 10PM */
            else if (startTime2 < 7) {
                /* If we ended before 12PM */
                if (endTime2 <= 7) {
                    total = ((endTime2 - startTime2) * 8);
                }
                /* If we didn't end before 12 PM */
                else {
                    total = ((7 - startTime2) * 8);
                    total += ((endTime2 - 7) * 16);
                }
            }
            /* If we didn't start before 12PM */
            else {
                total = ((endTime2 - 7) * 16);
            }
            break;

        case 'c':
        case 'C':
            /* 9PM is 4 on new range */
            /* If we started before 9PM */
            if (startTime2 < 4) {
                /* If we ended before 9PM */
                if (endTime2 <= 4) {
                    total = ((endTime2 - startTime2) * 21);
                }
                /* If we didn't end before 9PM */
                else {
                    total = ((4 - startTime2) * 21);
                    total += ((endTime2 - 4) * 15);
                }
            }
            /* If we didn't start before 9PM */
            else
                total = ((endTime2 - startTime2) * 15);
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
