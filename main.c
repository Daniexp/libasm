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
	printf("ft_strlen -> %ld\n", ft_strlen(str));
	printf("strlen -> %ld\n", strlen(str));
	printLine();
}

void test_strcpy(char *str)
{
	int len = strlen(str);
	char *strCpy = malloc(len + 1);
	if (!strCpy)
		return ;
	bzero((void *) strCpy, len + 1);

	printHeader("ft_strCpy");
	printf("Original -> %s\n", str);
	printf("ft_strcpy -> %s\n", ft_strcpy(strCpy, str));

	bzero((void *) strCpy, len + 1);

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
	printf("Fd1 -> %d\nFd2 -> %d\nString -> %s\nLen -> %d\n", fd, fd2, str, len);
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
	bzero((void *) buff, buffSize + 1);

	printHeader("ft_read");
	printf("Fd -> %d\nFd2 -> %d\nBuff Size -> %d\nRead bytes -> %d\n", fd, fd2, buffSize, nBytes);

	int ret;
	ret = ft_read(fd, buff, nBytes);

	printf("ft_read return -> %d\n", ret);
	printf("ft_read Buff -> %s\n", buff);
	printErrno(ret);

	bzero((void *) buff, buffSize + 1);

	ret = read(fd2, buff, nBytes);

	printf("read return -> %d\n", ret);
	printf("read Buff -> %s\n", buff);
	printErrno(ret);

	printLine();
	free(buff);
}

int openError(int *fds)
{
	int error = 0;
	if (!fds)
		error = 1;
	for (int i = 0; !error && fds[i]; i++)
		if (fds[i] == -1)
			error = 1;
	return error;
}

int *closeTestFiles(int *fds)
{
	if (!fds)
		return fds;
	for (int i = 0; fds[i]; i++)
		close(fds[i]);
	free(fds);
	fds = NULL;
	return fds;
}

void	deleteTestFiles(char **filenames)
{
	for (int i = 0; filenames[i]; i++)
		remove(filenames[i]);
}

int	*startTestFiles(char **filenames)
{
	int *fds = NULL;
	if (!filenames)
		return fds;
	int len = 0;
	while (filenames[len++]);

	fds = malloc(len);
	
	if (fds && filenames)
	{
		fds[0] = open(filenames[0], O_RDONLY | O_CREAT | O_APPEND, 0644);
		fds[1] = open(filenames[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		fds[2] = open(filenames[2], O_RDWR | O_CREAT | O_APPEND, 0644);
		fds[3] = open(filenames[3], O_RDONLY | O_CREAT | O_APPEND, 0644);
		fds[4] = open(filenames[4], O_WRONLY | O_CREAT | O_APPEND, 0644);
		fds[5] = open(filenames[5], O_RDWR | O_CREAT | O_APPEND, 0644);
		if (openError(fds))
		{
			fds = closeTestFiles(fds);
			deleteTestFiles(filenames);
		}
	}
	return fds;
}

int	setFilesPosition(int *fds, int whence)
{
	int error = 0;
	for (int i = 0; !error && fds[i]; i++)
	{
		if (lseek(fds[i], 0, whence) < 0)
			error = -1;
	}
	return error;
		
}

int main() {

	char *filenames[] = {"read.txt", "write.txt", "readWrite.txt", "read2.txt", "write2.txt", "readWrite2.txt", NULL};
	int *fds = startTestFiles(filenames);
	if (!fds)
		return printf("Issue creating test files\n"), 1;
	/*
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
	test_write(1, 1, "Hello, World!", ft_strlen("Hello, World!") * 2);
	test_write(0, 0, "Hello, World!", ft_strlen("Hello, World!"));
	test_write(-1, -1, "Hello, World!", ft_strlen("Hello, World!"));
	*/
	test_write(fds[0], fds[3], "Hello, World!", ft_strlen("Hello, World!"));
	test_write(fds[1], fds[4], "Hello, World!", ft_strlen("Hello, World!"));
	test_write(fds[2], fds[5], "Hello, World!", 13);

	setFilesPosition(fds, SEEK_SET);

	//Test read
	test_read(fds[0], fds[3], 20, 5);
	test_read(fds[1], fds[4], 20, 5);
	test_read(fds[2], fds[5], 20, 5);
	/*
	test_read(fds[2], fds2[2], 5, 5);
	test_read(fds[2], fds2[2], 50, 10);
	test_read(fds[2], fds2[2], 5, 50);
	test_read(-1, -1, 5, 5);
	*/

	//Test strdup
	/*
	strCpy = ft_strdup(str);
	printf("Copied String: %s", strCpy);
	free(strCpy);
	*/

	closeTestFiles(fds);
	deleteTestFiles(filenames);

	return 0;
}
