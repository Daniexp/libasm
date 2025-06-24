#ifndef TEST_H
#define TEST_H

#include "libasm.h"
#include "utils.h"

void test_strlen(char *str);
void test_strcpy(char *str);
void test_strcmp(char *str1, char*str2);
void test_write(int fd, int fd2, char *str, int len);
void test_read(int fd, int fd2, int buffSize, int nBytes);
void test_strdup(char *str);

#endif
