#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>

void	helloWorld(void);
size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s1);

#endif

