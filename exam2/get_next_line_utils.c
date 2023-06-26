/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:36:42 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/26 16:16:39 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if (!len || ft_strlen(str) < (size_t)start)
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
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strchr(const char *str, char set)
{
	char	*ref;

	if (!str)
		return (NULL);
	ref = str;
	while (ref && *ref != '\n')
		ref++;
	if (*ref != '\n')
		return (NULL);
	return (ref);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i)
}
