
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

size_t	endline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

static size_t	buflen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i] && i < 1024)
		i++;
	return (i);
}


char	*get_next_line(int fd)
{
	static char	*buffer = {0};
	char		*str;
	size_t		buffer_lenght;
	size_t		i;
	
	if (fd < 0)
		return (NULL);
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
	return (str);

}
