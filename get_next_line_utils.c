#include "get_next_line.h"

size_t	ft_strlen(char *buffer)
{
	size_t	i;

	i = 0 ;
	while (buffer[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	holder;

	holder = (char)c;
	while (*str)
	{
		if (*str == holder)
			return ((char *)str);
		str++;
	}
	if (*str == holder)
		return ((char *)str);
	return (NULL);
}

void	ft_lstaddback(t_buf HEAD, t_buf tmp)
{
	t_buf	t_iter;

	if (HEAD->next =)
		HEAD->next = tmp;
	t_iter = HEAD;
	while (t_iter)
		t_iter = t_iter->next;

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

