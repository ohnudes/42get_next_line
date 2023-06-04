#include "get_next_line.h"

size_t	ft_strlen(char *buffer)
{
	size_t	i;

	i = 0 ;
	while (buffer[i])
		i++;
	return (i);
}

size_t	ft_strchr(const char *str, int c)
{
	size_t	i;
	char	holder;

	i = 0;
	holder = (char)c;
	while (str[i])
	{
		if (str[i] == holder)
			return (i);
		i++;
	}
	if (str[i] == holder)
		return (i);
	return (0);
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

