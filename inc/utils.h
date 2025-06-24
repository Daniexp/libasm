#ifndef UTILS_H
#define UTILS_H

#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void printLine();
void printHeader(char *str);
void printErrno(int ret);

int *startTestFiles(char **filename);
int openError(int *fds);
int *closeTestFiles(int *fds);
void deleteTestFiles(char **filenames);

int setFilesPosition(int *fds, int whence);

#endif
