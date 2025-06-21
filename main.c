#include "libasm.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void printLine()
{
	printf("---------------------\n");
}

void printHeader(char *str)
{
	if (!str)
		return;
	printf("Test %s\n", str);
	printLine();
}

void printErrno(int ret)
{
	if (ret < 0)
		printf("Errno -> %s\n", strerror(errno));
}

void test_strlen(char *str)
{
	printHeader("ft_strlen");
	printf("String -> %s\n", str);
	printf("ft_strlen -> %d\n", ft_strlen(str));
	printf("strlen -> %d\n", strlen(str));
	printLine();
}

void test_strcpy(char *str)
{
	int len = strlen(str);
	char *strCpy = malloc(len + 1);
	if (!strCpy)
		return ;
	memset(strCpy, '\0', len);

	printHeader("ft_strCpy");
	printf("Original -> %s\n", str);
	printf("ft_strcpy -> %s\n", ft_strcpy(strCpy, str));

	memset(strCpy, '\0', len);

	printf("strcpy -> %s\n", strcpy(strCpy, str));
	printLine();

	free(strCpy);
}

void test_strcmp(char *str1, char *str2)
{
	printHeader("ft_strcmp");
	printf("String 1 -> %s\n", str1);
	printf("String 2 -> %s\n", str2);
	printf("ft_strcmp -> %d\n", ft_strcmp(str1, str2));
	printf("strcmp -> %d\n", strcmp(str1, str2));
	printLine();
}

void test_write(int fd, int fd2, char *str, int len)
{
	printHeader("ft_write");
	printLine();
	printf("Fd -> %d\nString -> %s\nLen -> %d\n", fd, str, len);
	int ret;
	ret = ft_write(fd, str, len);
	printf("\nft_write return -> %d\n", ret);
	printErrno(ret);
	ret = write(fd2, str, len);
	printf("\nwrite return -> %d\n", ret);
	printErrno(ret);
	printLine();
}

void test_read(int fd, int fd2, int buffSize, int nBytes)
{
	char *buff = malloc(buffSize + 1);
	if (!buff)
		return ;
	memset(buff, '\0', buffSize);

	printHeader("ft_read");
	printf("Fd -> %d\nFd2 -> %d\nBuff Size -> %d\nRead bytes -> %d\n", fd, fd2, buffSize, nBytes);

	int ret;
	ret = ft_read(fd, buff, buffSize);

	printf("ft_read return -> %d\n", ret);
	printf("ft_read Buff -> %s\n", buff);
	printErrno(ret);

	memset(buff, '\0', buffSize);

	ret = read(fd2, buff, buffSize);

	printf("read return -> %d\n", ret);
	printf("read Buff -> %s\n", buff);
	printErrno(ret);

	printLine();
	free(buff);
}

int openError(int *fds)
{
	int error = 0;
	for (int i = 0; i <= 2 && !error; i++)
		if (fds[i] == -1)
			error = 1;
	return error;
}

int *closeTestFiles(int *fds, int len)
{
	if (!fds)
		return fds;
	for (int j = 0; j < len; j++)
		close(fds[j]);
	free(fds);
	fds = NULL;
	return fds;
}

void	deleteTestFiles(char **filenames, int len)
{
	for (int i = 0; i < len; i++)
		remove(filenames[i]);
}

int	*startTestFiles(char **filenames, int len)
{
	int *fds = malloc(len);
	if (fds)
		for (int i = 0; i < len; i++)
			fds[i] = open(filenames[i], O_RDONLY | O_CREAT);
	if (openError(fds))
	{
		fds = closeTestFiles(fds, len);
		deleteTestFiles(filenames, len);
	}
	return fds;
}

int main() {
	int files = 3;
	char *filenames[3] = {"read.txt", "write.txt", "readWrite.txt"};
	int *fds = startTestFiles(filenames, files);
	if (!fds)
		return printf("Issue creating test files\n"), 1;
	char *filenamesDup[3] = {"read2.txt", "write2.txt", "readWrite2.txt"};
	int *fds2 = startTestFiles(filenamesDup, files);
	if (!fds2)
		return closeTestFiles(fds, files), printf("Issue opening duplicate test files\n"), 1;

	//Test strlen
	test_strlen("Hello, World!");
	test_strlen("");
	//Test strcpy
	test_strcpy("Hello, World!");
	test_strcpy("");
	//Test strcmp
	test_strcmp("Hello", "Hello");
	test_strcmp("", "");
	test_strcmp("testing1", "testing2");
	test_strcmp("Testing", "testing");
	//Test write
	test_write(1, 1, "Hello, World!", ft_strlen("Hello, World!"));
	test_write(1, 1, "Hello, World!", 5);
	test_write(1, 1, "Hello\0, World!", ft_strlen("Hello, World!") * 2);
	test_write(0, 0, "Hello, World!", ft_strlen("Hello, World!"));
	test_write(-1, -1, "Hello, World!", ft_strlen("Hello, World!"));
	test_write(fds[0], fds2[0], "Hello, World!", ft_strlen("Hello, World!"));
	test_write(fds[1], fds2[1], "Hello, World!", ft_strlen("Hello, World!"));
	test_write(fds[2], fds2[2], "Hello, World!", ft_strlen("Hello, World!"));

	//Test read
	test_read(fds[0], fds2[0], 13, 13);
	test_read(fds[1], fds2[1], 13, 13);
	test_read(fds[2], fds2[2], 13, 13);
	test_read(fds[2], fds2[2], 5, 5);
	test_read(fds[2], fds2[2], 50, 10);
	test_read(fds[2], fds2[2], 5, 50);
	test_read(-1, -1, 5, 5);

	//Test strdup
	/*
	strCpy = ft_strdup(str);
	printf("Copied String: %s", strCpy);
	free(strCpy);
	*/

	closeTestFiles(fds, files);
	deleteTestFiles(filenames, files);
	closeTestFiles(fds2, files);
	deleteTestFiles(filenamesDup, files);
	return 0;
}
