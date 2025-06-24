#include "utils.h"

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
		if (lseek(fds[i], 0, whence) < 0)
			error = -1;
	return error;
		
}

