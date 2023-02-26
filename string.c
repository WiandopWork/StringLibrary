#include <stdio.h>
#include "string.h"
#include <stdlib.h>

/**
 * @brief String comparison
 * @details The function compares each element of a row with an element of another row
 * @param str1 First string
 * @param str2 Second string
 * @return '0' if the strings match and not '0' if they don't match
 */
int myStrcmp(char* str1, char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return -1;
    }

    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}


/**
 * @brief Determining the length of a string
 * @details The function calculates the number of elements up to '\0'
 * @param str String value
 * @return A variable with a length value
 */
int myStrlen(char* str) {
    if (str == NULL) {
        return -1;
    }

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    return len;
}


/**
 * @brief Copying a string
 * @details Copies characters from one string to another, subject to length
 * @param source The string from which the data is copied
 * @param target The string to which the data is copied
 * @param source_bit_len The bit length of the string from which the data is copied
 * @param target_bit_len The bit length of the string to which the data is copied
 * @return The copied string or NULL
 */
char* myStrcpy(char* source, char* target, size_t source_bit_len, size_t target_bit_len) {
    if (source == NULL || target == NULL) {
        return NULL;
    }

    if ((int)(target_bit_len - source_bit_len) < 0) {
        return NULL;
    } else {
        for (int i = 0; i <= myStrlen(source); i++) {
            target[i] = source[i];
        }
        return target;
    }
}


/**
 * @brief Searching for a character in a string
 * @details Search for the first matching character in a string
 * @param source The string in which the character is being searched
 * @param symbol Symbol to search for
 * @return The line after this character or NULL
 */
char* myStrchr(char* source, int symbol) {
    if (source == NULL) {
        return NULL;
    }

    while (*source != (char) symbol) {
        if (*source == '\0') {
            return NULL;
        }
        source++;
    }

    return (char*) source;
}


/**
 * @brief Duplicating a string
 * @details Copying a string using malloc. This function allocates memory, it needs to be cleaned up
 * @param source String to duplicate
 * @see myStrcpy
 * @return Duplicated string
 */
char* myStrdup(char* source) {
    if (source == NULL) {
        return NULL;
    }

    char* target = (char*) calloc(myStrlen(source) + 1, sizeof(char));
    target = myStrcpy(source, target, sizeof(source), myStrlen(source)+1);

    return target;
}

/**
 * @brief Comparison of num elements of strings
 * @param str1 First string
 * @param str2 Second string
 * @param num
 * @return Numerical difference of characters in strings
 */
int myMemcmp(char* str1, char* str2, size_t num) {
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }

    for (size_t i = 0; i < num; i++) {
        if (str1[i] == str2[i]) {
            if (i+1 == myStrlen(str2)) {
                return 0;
            }

            continue;
        } else if (str1[i] > str2[i]) {
            return (str1[i] - str2[i]);
        } else if (str1[i] < str2[i]) {
            return (str1[i] - str2[i]);
        }

        str1++;
        str2++;

        if (i+1 == myStrlen(str2)) {
            return 0;
        }
    }
    return 0;
}

/**
 * @brief Searching for a substring in a string
 * @param source Search string
 * @param value Search value
 * @return A string starting from the found substring or NULL
 */
char* myStrstr(char* source, char* value) {
    size_t source_len, value_len;

    source_len = myStrlen(source);
    value_len = myStrlen(value);

    if (source == NULL || value == NULL) {
        return NULL;
    }

    if (value_len == 0) {
        return (char *) source;
    }

    while (source_len >= value_len) {
        source_len--;
        if (myMemcmp(source, value, value_len) == 0) {
            return (char*) source;
        }
        source++;
    }
    return NULL;
}

/**
 * @brief Searching for the position of a symbol in the range
 * @details Finds a character in a restricted area of the string
 * @param source Search string
 * @param symbol Symbol to search for
 * @param len Search range
 * @return The position of the first matching character or NULL
 */
void* myMemchr(void* source, int symbol, size_t len) {
    char* buf_source = source;
    if (buf_source == NULL) {
        return NULL;
    }

    for (int pos = 0; pos <= len; pos++) {
        if (buf_source[pos] == (char) symbol) {
            return &buf_source[pos];
        }
    }

    return NULL;
}


/**
 * @brief Copying elements in the range
 * @details Copying elements of a certain number of elements
 * @param source String to copy
 * @param target The term of the received value
 * @param num Number of characters
 * @return The copied string or NULL
 */
void* myMemcpy (void* source, void* target, size_t num) {
    char* buf_source = source;
    char* buf_target = target;

    if (buf_source == NULL || buf_target == NULL) {
        return NULL;
    }

    if (num > myStrlen(source)) {
        return NULL;
    }

    for (size_t i = 0; i < num; i++) {
        buf_target[i] = buf_source[i];
    }

    return buf_target;
}


/**
 * @brief Replacing elements
 * @details Replacing a limited number of elements with a new symbol
 * @param mem_target Copy and Replace string
 * @param value Symbol to replace
 * @param num Number of items to replace
 * @return A string with replaced elements or NULL
 */
void* myMemset(void* mem_target, int value, size_t num) {
    char* buf_target = mem_target;
    if (buf_target == NULL) {
        return NULL;
    }

    if (num > myStrlen(mem_target)) {
        return NULL;
    }

    for (size_t i = 0; i < num; i++) {
        buf_target[i] = value;
    }

    return buf_target;
}

