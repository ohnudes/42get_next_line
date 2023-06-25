/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:13:47 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/25 21:46:07 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start || !len)
	{
		substr = malloc(sizeof(char) * 1);
		*substr = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char set)
{
	int	i;

	i = 0;
	while (str[i] != set && str[i])
		i++;
	if (str[i] != set)
		return (-1);
	return (i);
}

char	*ft_strjoin_t(char **s1, char **s2)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(*s1) + ft_strlen(*s2);
	result = malloc(sizeof(char) * (len + 1));
	while (i < ft_strlen(*s1))
	{
		result[i] = *s1[i];
		i++;
	}
	while (j < ft_strlen(*s2))
	{
		result[i + j] = *s2[j];
		j++;
	}
	result[len] = '\0';
	free (*s2);
	s2 = NULL;
	return (result);
}
