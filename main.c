#include "mylib.h"
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	helloWorld();
	char *str = "Hello, World!\n";
	printf("%d\n", ft_strlen(str));
	char *strCpy = malloc(ft_strlen(str) + 1);
	strCpy = ft_strcpy(strCpy, str);
	printf("Copied string: %s", strCpy);
	char big[20];
	printf("%s\n", ft_strcpy(big, str));
	char *str2 = malloc(ft_strlen(str) + 1);
	str2 = 	ft_strcpy(str2, str);
	printf("Comparison: %d\n", ft_strcmp(str, str2));

	//Test write
	ft_write(1, str, ft_strlen(str));
	
	free(strCpy);
	free(str2);

	int fd = open("example.txt", O_RDONLY);
	char buffer[6];
	printf("Bytes readed: %d\n", ft_read(fd, buffer, 5));
	buffer[5] = '\0';
	printf("example.txt: %s\n", buffer);
	return 0;
}
