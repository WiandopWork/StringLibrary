#ifndef PROJECT_TESTS_H
#define PROJECT_TESTS_H

typedef enum {
    OK,
    failed
} errors;

int run_all_tests();
errors test_myStrcmp();
errors test_myStrlen();
errors test_myStrcpy();
errors test_myStrchr();
errors test_myStrdup();
errors test_myMemcmp();
errors test_myStrstr();
errors test_myMemchr();
errors test_myMemcpy();
errors test_myMemset();

#endif
