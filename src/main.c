#include "test.h"

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
