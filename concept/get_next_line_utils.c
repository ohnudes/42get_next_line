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

// finished
char	*ft_strjoin_t(char *content, char *suffix)
{
	char	*newcont;
	char	*appex;
	size_t	aplen;
	size_t	sulen;

	appex = buffer->content;
	aplen = ft_strchr(appex, '\0') - 1;
	sulen = ft_strchr(suffix, '\0') - 1;
	newcont = malloc(sizeof(char) * (aplen + sulen + 1));
	if (!newcont)
		return (NULL);
	while (appex)
		newcont++ = appex++;
	while (suffix)
		newcont++ = suffix++;
	newcont[aplen + sulen] = '\0';
	return (newcont);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

int	error_protocol()
{
	

	return (0);
}
