#include "get_next_line.h"

// finished
size_t	ft_strchr(char *content, char set)
{
	size_t	i;

	i = 0;
	while (content[i] && content[i] != set)
		i++;
	if (content[i] == set)
		return (i);
	return (0);
}

// finished
char	*ft_substr(char *error, char *content, size_t match)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (match + 1));
	if (!str)
	{
		*error = -1;
		return (NULL);
	}
	i = 0;
	while (i < match)
		str[i] = content[0]);
	str[match] = '\0';
	return (str);
}

// indev
char	*ft_downsize_t(t_buf buffer)
{
	char	*restr;
	size_t	maxlen;

	maxlen = buffer->len - match;
	buffer->len = ft_strlen(buffer->content[match]);
	restr = malloc(sizeof(char) * (maxlen + 1));
	if (!restr)
		buffer->error = -1;
	if (!buffer->error)
	{
		restr = ft_substr(error, newbuf, buffer->len);
		if (!restr)
		{
		
			return (NULL);
		free (buffer->content);
	}
	if (buffer->error)
		return (NULL);
	return (restr);
}

char	*ft_strjoin_t()
{


}
