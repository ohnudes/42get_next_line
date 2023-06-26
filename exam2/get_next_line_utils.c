/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:36:42 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/26 18:40:17 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_t(char *s1, char *s2)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		result[i + j] = s2[j];
		j++;
	}
	result[len] = '\0';
	free (s1);
	s1 = NULL;
	return (result);
}

char	*ft_substr(char **str, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!*str)
		return (NULL);
	if (!len || ft_strlen(*str) < (size_t)start)
	{
		result = malloc(sizeof(char) * 1);
		if (!result)
			return (ft_free(&result));
		*result = '\0';
		return (result);
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (ft_free(&result));
	i = 0;
	while (i < len && *str[start + i])
	{
		result[i] = *str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strchr(const char *str, char set)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != set)
		i++;
	if (str[i] != set)
		return (-1);
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
