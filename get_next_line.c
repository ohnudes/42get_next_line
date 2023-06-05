
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*buffer_checker(char *buffer, int fd)
{
	ssize_t	i;
	char	*tmp;

	i = 1;
	while (!strchr(tmp, '\n') && i > 0)
	{
		i =	read(fd, tmp, BUFFER_SIZE);
		tmp = malloc(sizeof(char) * (i + 1));
		if (!tmp)
			return (NULL);
		buffer = ft_strjoin(buffer, tmp);
		free (tmp);
	}
	return (buffer);
}

char	*do_str(char *buffer, int fd)
{
	char	*str; //create result
	char	*tmp_buf; //tmp buffer to create reference point for result to copy.
	size_t	ref; // reference for end of buffer.
	size_t	i;	// reference for lenght of tmp_buf, later applied on malloc
	size_t	si; // index for str while copying.

	tmp_buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp_buf)
		return (NULL);
	if (read(fd, tmp_buf, BUFFER_SIZE) < 0)
		return (NULL);
	ref = ft_strlen(buffer);
	i = 0;
	while (tmp_buf[ref + i] != '\n' && tmp_buf)
		i++;
	str = malloc(sizeof(char) * i + 1);
	si = 0;
	while (si < i - 1)
	{
		str[si] = tmp_buf[ref + si];
		si++;
	}
	str[i] = '\0';	
	return (str);
}

char	*extend_buffer(char *buffer, char *str, int fd)
{
	size_t	buffer_lenght;
	size_t	str_len;

	buffer_lenght = ft_strlen(buffer);
	if (str_len > BUFFER_SIZE - buffer_lenght)
	{}
		// restart buffer? keep position compared where was left?
		// what if BUFFER_SIZE is 1? is 10gb?
	ft_strjoin(buffer, str);
	return (buffer);
}


char	*get_next_line(int fd)
{
	static char	*buffer = {0};
	char		*str;
	
	if (fd < 0)
		return (NULL);

	// loads the buffer
	buffer = buffer_checker(buffer, fd);

	// creates the string: malloc!
	str = do_str(buffer, fd);
	if (!str)
		return (NULL);

	// adds newly created string to the end of buffer.
	// checks remaning buffer
	buffer = extend_buffer(buffer, str, fd);
	
	return (str);
}

int	main(int argc, char **argv)
{
	ssize_t	fd;

	fd = open(*argv, O_RDONLY);
	get_next_line(fd);
	close(int);

	return (0);
}
/*
if (!buffer)
{
	buffer_lenght = buflen(buffer);
	read(fd, buffer, buffer_lenght);
	str = malloc(sizeof(char) * (endline(buffer) + 1));
	i = 0;
	while (i < endline(buffer))
	{
		str[i] = buffer[i];
	}
}

else
return (str);*/
