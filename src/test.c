#include "test.h"

void test_strlen(char *str)
{
	printHeader("ft_strlen");
	printf("String -> %s\n", str);
	printf("ft_strlen -> %zu\n", ft_strlen(str));
	printf("strlen -> %zu\n", strlen(str));
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

void test_strdup(char *str)
{
	if (!str)
		return ;
	printHeader("ft_strdup");
	printf("String -> %s\n", str);

	char *strCpy = ft_strdup(str);
	printf("ft_strdup -> %s\n", strCpy);
	free(strCpy);

	strCpy = strdup(str);
	printf("strdup -> %s\n", strCpy);
	free(strCpy);

	printLine();
}

