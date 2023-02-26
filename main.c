#include <stdio.h>
#include "string.h"
#include "tests/tests.h"

/**
 * OUTPUT_LANGUAGE = English
 * PROJECT_NAME = String library
 * PROJECT_NUMBER = 1.0.0
 * PROJECT_BRIEF = A program with the basic functions of the <string.h> library
 * OUTPUT_DIRECTORY = /doc
 */

/**
 * @brief Entry point
 * @detailed Execution of the program
 * starts here.
 * @return Program exit status
 */

int main() {
    run_all_tests();
    printf("All tests passed!\n");
    return 0;
}
