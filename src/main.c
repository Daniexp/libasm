#include "libasm.h"
#include "utils.h"

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

int main() {

	char *filenames[] = {"read.txt", "write.txt", "readWrite.txt", "read2.txt", "write2.txt", "readWrite2.txt", NULL};
	int *fds = startTestFiles(filenames);
	if (!fds)
		return printf("Issue creating test files\n"), 1;
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
	test_write(fds[0], fds[3], "Hello, World!", ft_strlen("Hello, World!"));
	test_write(fds[1], fds[4], "Hello, World!", ft_strlen("Hello, World!"));
	char *str = "Hello these is an example for the read and write file...!!!\nNext line example.";
	test_write(fds[2], fds[5], str, ft_strlen(str));

	setFilesPosition(fds, SEEK_SET);

	//Test read
	test_read(fds[0], fds[3], 20, 5);
	test_read(fds[1], fds[4], 20, 5);
	test_read(fds[2], fds[5], 20, 5);
	test_read(fds[2], fds[5], 5, 5);
	test_read(fds[2], fds[5], 50, 10);
	test_read(fds[2], fds[5], 80, 80);
	test_read(-1, -1, 5, 5);

	//Test strdup
	test_strdup("Hello, World!");
	test_strdup("");
	test_strdup("\0\0\0\0");
	test_strdup(NULL);

	closeTestFiles(fds);
	deleteTestFiles(filenames);

	return 0;
}
