/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:30:58 by nmaturan          #+#    #+#             */
/*   Updated: 2023/09/04 18:00:30 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strappend(const char *first, const char *second, int rbytes)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	slen;

	i = 0;
	j = 0;
	slen = rbytes;
	newstr = malloc(sizeof(char) * (ft_strlen(first) + slen) + 1);
	if (!newstr)
		return (NULL);
	while (i < ft_strlen(first))
	{
		newstr[i] = first[i];
		i++;
	}
	while (j < slen)
	{
		newstr[i + j] = second[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *str, char set)
{
	char	*occurrence;

	if (!str)
		return (NULL);
	occurrence = (char *)str;
	while (*occurrence != set && *occurrence != '\0')
		occurrence++;
	if (*occurrence == set)
		return (occurrence);
	return (NULL);
}

char	*ft_free(char *str)
{
	if (*str)
		free (str);
	return (NULL);
}
