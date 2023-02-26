#include <stdlib.h>
#ifndef PROJECT_STRING_H
#define PROJECT_STRING_H

int myStrlen(char* str);
int myStrcmp(char* str1, char* str2);
char* myStrcpy(char* source, char* target, size_t source_bit_len, size_t target_bit_len);
char* myStrchr(char* str, int symbol);
char* myStrdup(char* source);
int myMemcmp(char* str1, char* str2, size_t num);
char* myStrstr(char* source, char* value);
void* myMemchr(void* str, int symbol, size_t len);
void* myMemcpy (void* source, void* target, size_t num);
void* myMemset(void* mem_target, int value, size_t num);
#endif
