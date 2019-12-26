/* Includes */
#include <stdio.h>
#include <assert.h>
#include "babysitter.h"

int main () {
    int result = 0;
    int test = 0;
    int failed = 0;

    /* Test 1
     * Maximum Times and Family A
     * Expected Value 190
     * (90) + (100)*/
    test++;
    result = babysitter('a',17,4);
    if (result != 190) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 2
     * Maximum Times and Family B
     * Expected Value 140
     * (60) + (16) + (64) */
    test++;
    result = babysitter('b',17,4);
    if (result != 140) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 3
     * Maximum Times and Family C
     * Expected Value 189
     * (84) + (105) */
    test++;
    result = babysitter('c',17,4);
    if (result != 189) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 4
     * Maximum Times and Family D
     * Expected Value -3 (INVALID_FAMILY)
     **/
    test++;
    result = babysitter('d',17,4);
    if (result != INVALID_FAMILY) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 5
     * Invalid Start Time and Family A
     * Expected Value -1 (INVALID_START)
     **/
    test++;
    result = babysitter('a',16,4);
    if (result != INVALID_START) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 6
     * Invalid End Time and Family A
     * Expected Value -2 (INVALID_END)
     **/
    test++;
    result = babysitter('a',17,5);
    if (result != INVALID_END) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 7
     * Invalid Start Time and Family B
     * Expected Value -1 (INVALID_START)
     **/
    test++;
    result = babysitter('b',16,4);
    if (result != INVALID_START) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 8
     * Invalid End Time and Family B
     * Expected Value -2 (INVALID_END)
     **/
    test++;
    result = babysitter('b',17,5);
    if (result != INVALID_END) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 9
     * Invalid Start Time and Family C
     * Expected Value -1 (INVALID_START)
     **/
    test++;
    result = babysitter('c',16,4);
    if (result != INVALID_START) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 10
     * Invalid End Time and Family C
     * Expected Value -2 (INVALID_END)
     **/
    test++;
    result = babysitter('c',17,5);
    if (result != INVALID_END) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 11
     * Invalid Start Time and Family D (Both Invalid)
     * Expected Value -1 (INVALID_START)
     **/
    test++;
    result = babysitter('d',16,4);
    if (result != INVALID_START) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 12
     * Invalid End Time and Family D
     * Expected Value -2 (INVALID_END)
     **/
    test++;
    result = babysitter('d',17,5);
    if (result != INVALID_END) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Basic Sanity Tests Completed */
    /* Corner Cases and Fuzz Testing */

    /* Test 13
     * Start time Equal to End time test
     * Expected Value 0
     **/
    test++;
    result = babysitter('a',17,17);
    if (result != 0) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 14
     * Expected Value 30
     * Family A First Half-Only
     **/
    test++;
    result = babysitter('a',17,19);
    if (result != 30) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 15
     * Expected Value 100
     * Family A Second Half-Only
     **/
    test++;
    result = babysitter('a',23,4);
    if (result != 100) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 16
     * Expected Value 60
     * Family B First Third-Only
     **/
    test++;
    result = babysitter('b',17,22);
    if (result != 60) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 17
     * Expected Value 16
     * Family B Second Third-Only
     **/
    test++;
    result = babysitter('b',22,24);
    if (result != 16) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 18
     * Expected Value 64
     * Family B Last Third-Only
     **/
    test++;
    result = babysitter('b',24,4);
    if (result != 64) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 19
     * Expected Value 84
     * Family C First Half-Only
     **/
    test++;
    result = babysitter('c',17,21);
    if (result != 84) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 20
     * Expected Value 84
     * Family C Second Half-Only
     **/
    test++;
    result = babysitter('c',21,4);
    if (result != 105) {
        failed++;
        printf("Test %d Failed \n", test);
    }

    /* Test 21
     * Maximum Times (Fractional)
     * Typecasts should take care of this
     * Expected Value 190
     * (90) + (100)*/
    test++;
    result = babysitter('a',17.7,4);
    if (result != 190) {
        failed++;
        printf("Test %d Failed \n", test);
    }

     /* Test 22
     * Maximum Times -- Capital Character
     * Expected Value 190
     * (90) + (100)*/
    test++;
    result = babysitter('A',17,4);
    if (result != 190) {
        failed++;
        printf("Test %d Failed \n", test);
    }



    /* Return error if tests failed */
    if (failed > 0) {
        printf("%d Tests failed \n", failed);
        return ERROR;
    }
    else {
        printf("All tests passed!\n");
        return SUCCESS;
    }
}
