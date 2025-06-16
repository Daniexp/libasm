#include "mylib.h"

int main() {
	helloWorld();
	char *str = "Hello, World";
	printf("%d\n", ft_strlen(str));
	char *strCpy = malloc(ft_strlen(str) + 1);
	strCpy = ft_strcpy(strCpy, str);
	printf("Copied string: %s\n", strCpy);

	return 0;
}
