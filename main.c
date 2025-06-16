#include "mylib.h"

int main() {
	helloWorld();
	char *str = "Hello, World!";
	printf("%d\n", ft_strlen(str));
	char *strCpy = malloc(ft_strlen(str) + 1);
	strCpy = ft_strcpy(strCpy, str);
	printf("Copied string: %s\n", strCpy);
	char big[20];
	printf("%s\n", ft_strcpy(big, str));

	free(strCpy);
	return 0;
}
