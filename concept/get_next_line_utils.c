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
char	*ft_substr(char *content, size_t match)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (match + 1));
	if (str)
	{
		i = 0;
		while (i < match)
		{
			str[i] = content[i]);
			i++;
		}
		str[match] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin_t(t_buf buffer, char *suffix)
{
	char	*newcont;
	char	*appex;
	size_t	aplen;
	size_t	sulen;

	appex = buffer->content;
	aplen = ft_strchr(appex, '\0');
	sulen = ft_strchr(suffix, '\0');
	newcont = malloc(sizeof(char) * (aplen + sulen + 1));
	if (!newcont)
		return (NULL);
	while (appex)
		newcont++ = appex++;
	while (suffix)
		newcont++ = suffix++;
	newcont[aplen + sulen + 1] = '\0';
	return (newcont);
	}
}

int	error_protocol()
{


	return (0);
}
