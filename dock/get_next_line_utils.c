/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:08:52 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/25 17:12:14 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *content, char set)
{
	size_t	i;

	i = 0;
	while (content[i] && content[i] != set)
		i++;
	if (content[i] == set)
		return (i);
	return (-1);
}

char	*ft_substr(char *content, size_t match)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (match + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < match)
	{
		str[i] = content[i];
		i++;
	}
	str[match] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	reslen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	reslen = ft_strchr(s1, '\0') + ft_strchr(s2, '\0') - 2;
	result = malloc(sizeof(char) * (reslen + 1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
