#include "tests.h"
#include <stdio.h>
#include <assert.h>
#include "../string.h"
const void* wrong_string = NULL;

int run_all_tests() {
    assert(OK == test_myStrcmp());
    assert(OK == test_myStrlen());
    assert(OK == test_myStrcpy());
    assert(OK == test_myStrchr());
    assert(OK == test_myStrdup());
    assert(OK == test_myMemcmp());
    assert(OK == test_myStrstr());
    assert(OK == test_myMemchr());
    assert(OK == test_myMemcpy());
    assert(OK == test_myMemset());
}

// Test myStrcmp

errors test_myStrcmp() {
    printf("Testing myStrcmp(). \n");

    char test_string1[] = "Hello";
    char test_string2[] = "Hello";

    // Test first NULL value
    if (myStrcmp((char*)wrong_string, test_string2) != -1) {
        return failed;
    }

    // Test second NULL value
    if (myStrcmp(test_string1, (char*)wrong_string) != -1) {
        return failed;
    }

    // Program performance test
    if (myStrcmp(test_string1, test_string2) != 0) {
        return failed;
    }

    char test_string3[] = "Hi";

    // Wrong performance test
    if (myStrcmp(test_string1, test_string3) == 0) {
        return failed;
    }

    printf("Testing myStrcmp() completed! \n \n");
    return OK;
}

// Test myStrlen

errors test_myStrlen() {
    printf("Testing myStrlen(). \n");

    char test_string[] = "Hello";

    // Test NULL value
    if (myStrlen((char*)wrong_string) != -1) {
        return failed;
    }

    // Program performance test
    if (myStrlen(test_string) != 5) {
        return failed;
    }

    printf("Testing myStrlen() completed! \n \n");
    return OK;
}


// Test myStrcpy

errors test_myStrcpy() {
    printf("Testing myStrcpy(). \n");

    char test_string[] = "Hello world";
    char target_string[16];
    char wrong_target_string[2];
    char res[] = "Hello world";

    // Test first NULL value
    if (myStrcpy((char*)wrong_string, target_string, sizeof(test_string), sizeof(target_string)) != NULL) {
        return failed;
    }

    // Test second NULL value
    if (myStrcpy(test_string, (char*)wrong_string, sizeof(test_string), sizeof(target_string)) != NULL) {
        return failed;
    }

    // Length test
    if (myStrcpy(test_string, wrong_target_string, sizeof(test_string), sizeof(wrong_target_string)) != NULL) {
        return failed;
    }

    // Program performance test
    if (myStrcmp(res, myStrcpy(test_string, target_string, sizeof(test_string), sizeof(target_string))) != 0) {
        return failed;
    }

    printf("Testing myStrcpy() completed! \n \n");
    return OK;
}


// Test myStrchr

errors test_myStrchr() {
    printf("Testing myStrchr(). \n");

    char test_string[] = "Star* wars";

    // Test NULL value
    if (myStrchr((char*)wrong_string, '*') != NULL) {
        return failed;
    }

    // Program performance test
    if ((myStrchr(test_string, '*') - test_string + 1) != 5) {
        return failed;
    }

    // Wrong performance test
    if (myStrchr(test_string, ')') != NULL) {
        return failed;
    }

    printf("Testing myStrchr() completed! \n \n");
    return OK;
}


// Test myStrdup

errors test_myStrdup() {
    printf("Testing myStrdup(). \n");

    char test_string[] = "Linux Ubuntu";
    char res[] = "Linux Ubuntu";

    // Test NULL value
    if (myStrdup((char*)wrong_string) != NULL) {
        return failed;
    }

    char* target_string = myStrdup(test_string);

    // Program performance test
    if (myStrcmp(res, target_string) != 0) {
        return failed;
    }

    // Memory clear
    free(target_string);

    printf("Testing myStrdup() completed! \n \n");
    return OK;
}

// Test myMemcmp

errors test_myMemcmp() {
    printf("Testing myMemcmp(). \n");

    char test_string1[] = "Linux";
    char test_string2[] = "Linux";

    // Test first NULL value
    if (myMemcmp((char*)wrong_string, test_string2, 3) != 0) {
        return failed;
    }

    // Test second NULL value
    if (myMemcmp(test_string1, (char*)wrong_string, 3) != 0) {
        return failed;
    }

    // First program performance test

    if (myMemcmp(test_string1, test_string2, 4) != 0) {
        return failed;
    }

    char test_string3[] = "Hi";

    // Second program performance test

    if (myMemcmp(test_string1, test_string3, 2) != 4) {
        return failed;
    }

    char test_string4[] = "Qwerty";

    // Third program performance test

    if (myMemcmp(test_string1, test_string4, 3) != -5) {
        return failed;
    }

    // Wrong performance test

    char wrong_test_string[] = "Li";

    if (myMemcmp(test_string1, wrong_test_string, 2) != 0) {
        return failed;
    }

    printf("Testing myMemcmp() completed! \n \n");
    return OK;
}


// Test myStrstr

errors test_myStrstr() {
    printf("Testing myStrstr(). \n");

    char test_string[] = "abacabacaba";
    char target_string1[] = "";
    char result_string1[] = "abacabacaba";

    // Test first NULL value
    if (myStrstr((char*)wrong_string, target_string1) != NULL) {
        return failed;
    }

    // Test second NULL value
    if (myStrstr(test_string, (char*)wrong_string) != NULL) {
        return failed;
    }

    // First program performance test
    if (myStrcmp(result_string1, myStrstr(test_string, target_string1)) != 0) {
        return failed;
    }

    char target_string2[] = "caba";
    char result_string2[] = "cabacaba";

    // Second program performance test
    if (myStrcmp(result_string2, myStrstr(test_string, target_string2)) != 0) {
        return failed;
    }

    char target_string3[] = "ui";

    // Wrong performance test
    if (myStrstr(test_string, target_string3) != NULL) {
        return failed;
    }

    printf("Testing myStrstr() completed! \n \n");
    return OK;
}


// Test myMemchr

errors test_myMemchr() {
    printf("Testing myMemchr(). \n");

    char test_string[] = "abacaba";

    // Test NULL value
    if (myMemchr((char*)wrong_string, 'c', myStrlen(test_string)) != NULL) {
        return failed;
    }

    int res = 0000000000000063;

    // Program performance test
    if (myMemchr(test_string, 'c', myStrlen(test_string) != res)) {
        return failed;
    }

    // Wrong performance test
    if (myMemchr(test_string, ')', myStrlen(test_string)) != NULL) {
        return failed;
    }

    printf("Testing myMemchr() completed! \n \n");
    return OK;
}


// Test myMemcpy

errors test_myMemcpy() {
    printf("Testing myMemcpy(). \n");

    char test_string[] = "Linux Ubuntu";
    char target_string[15];
    char result_string[] = "Linux";

    // Test first NULL value
    if (myMemcpy((char*)wrong_string, target_string, 5) != NULL) {
        return failed;
    }

    // Test second NULL value
    if (myMemcpy(test_string, (char*)wrong_string, 5) != NULL) {
        return failed;
    }

    // Program performance test
    if (myStrcmp(result_string, myMemcpy(test_string, target_string, 5)) != 0) {
        return failed;
    }

    // Length test
    if (myMemcpy(test_string, target_string, 58) != NULL) {
        return failed;
    }

    printf("Testing myMemcpy() completed! \n \n");
    return OK;
}


// Test myMemset

errors test_myMemset() {
    printf("Testing myMemset(). \n");

    char test_string[] = "String library";
    char res_string[] = "****ng library";

    // Test NULL value
    if (myMemset((char*)wrong_string, '*', 4) != NULL) {
        return failed;
    }

    // Program performance test
    if (myStrcmp(myMemset(test_string, '*', 4), res_string) != 0) {
        return failed;
    }

    // Length test
    if (myMemset(test_string, '*', 19) != NULL) {
        return failed;
    }

    printf("Testing myMemset() completed! \n \n");
    return OK;
}