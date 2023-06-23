#include "get_next_line.h"

size_t	ft_strchr_t(t_buf *buffer)
{
	char	*str;
	char	*match;
	size_t		i;

	str = buffer->content;
	while (str[i] && i < buffer->len && str[i] != '\n')
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (i);
	return (0);
}

char	*ft_substr(char *content, size_t match, char error)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (buffer->match + 1));
	if (!str)
	{
		buffer->error = -1;
		str = NULL;
		return (NULL);
	}
	while (i < buffer->match)
		str[i] = buffer->content[i];
	str[buffer->match] = '\0';
	return (str);
}

char	*ft_resize_t(t_buf *buffer, int offset)
{
	char	*newbuf;
	size_t	i;

	newbuf = buffer->content + offset;
	ft_substr()
}
