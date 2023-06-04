#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

#define BUFFER_SIZE 1024

#include <unistd.h>

char	*get_next_line(int fd);
char	*get_next_line_utils(int fd);

size_t	ft_strlen(char *buffer);
size_t	ft_strjoin(const char *s1, const char *s2);

#endif
