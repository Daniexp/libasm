#include "mylib.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

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

void test_strlen(char *str)
{
	printHeader("ft_strlen");
	printf("String -> %s", str);
	printf("ft_strlen -> %d\n", ft_strlen(str));
	printf("strlen -> %d\n", strlen(str));
	printLine();
}

void test_strCpy(char *str)
{
	printHeader("ft_strCpy");
}

int main() {
	//Test strlen
	char *str = "Hello, World!\n";
	test_strlen(str);
	test_strlen("");
	//Test strcpy
	char *strCpy = malloc(ft_strlen(str) + 1);
	strCpy = ft_strcpy(strCpy, str);
	printf("Copied string: %s", strCpy);
	char big[20];
	printf("%s\n", ft_strcpy(big, str));
	//Test strcmp
	char *str2 = malloc(ft_strlen(str) + 1);
	str2 = 	ft_strcpy(str2, str);
	printf("Comparison: %d\n", ft_strcmp(str, str2));

	//Test write
	ft_write(1, str, ft_strlen(str));
	
	free(strCpy);
	free(str2);

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
	return 0;
}
