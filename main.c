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
		printf("Errno ->%s\n", strerror(errno));
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
	char *strCpy = malloc(strlen(str) + 1);
	char *strCpy2 = malloc(strlen(str) + 1);

	printHeader("ft_strCpy");
	printf("Original -> %s\n", str);
	printf("ft_strcpy -> %s\n", ft_strcpy(strCpy, str));
	printf("strcpy -> %s\n", strcpy(strCpy2, str));
	printLine();

	free(strCpy);
	free(strCpy2);
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

void test_write(int fd, char *str, int len)
{
	printHeader("ft_write");
	printLine();
	printf("Fd -> %d\nString -> %s\nLen -> %d\n", fd, str, len);
	int ret;
	ret = ft_write(fd, str, len);
	printf("\nft_write return -> %d\n", ret);
	printErrno(ret);
	ret = write(fd, str, len);
	printf("\nwrite return -> %d\n", ret);
	printErrno(ret);
	printLine();
}

int main() {
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
	test_write(1, "Hello, World!", ft_strlen("Hello, World!"));
	test_write(1, "Hello, World!", 5);
	test_write(1, "Hello\0, World!", ft_strlen("Hello, World!") * 2);
	test_write(0, "Hello, World!", ft_strlen("Hello, World!"));
	test_write(-1, "Hello, World!", ft_strlen("Hello, World!"));

	/*
	//Test read
	int fd = open("example.txt", O_RDONLY);
	char buffer[6];
	printf("Bytes readed: %d\n", ft_read(fd, buffer, 5));
	buffer[5] = '\0';
	printf("example.txt: %s\n", buffer);

	//Test strdup
	strCpy = ft_strdup(str);
	printf("Copied String: %s", strCpy);
	free(strCpy);
	*/
	return 0;
}
