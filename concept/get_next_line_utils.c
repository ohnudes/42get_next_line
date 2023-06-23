#include "get_next_line.h"

size_t	ft_strchr_t(t_buf *buffer)
{
	char	*str;
	size_t		i;

	str = buffer->content;
	while (str[i] && i < buffer->len && str[i] != '\n')
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (i);
	return (0);
}

char	*ft_substr_t(char *content, size_t *match, char *error)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (*match + 1));
	if (!str)
	{
		*error = -1;
		return (NULL);
	}
	while (i < *match)
		str[i] = *(content + i);
	str[*match] = '\0';
	return (str);
}

char	*ft_resize_t(char *content, size_t *match)
{
	char	*newbuf;
	size_t	i;

	newbuf = content + *match;
	ft_substr(
}
