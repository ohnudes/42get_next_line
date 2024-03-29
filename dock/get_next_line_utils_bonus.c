/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:32:42 by nmaturan          #+#    #+#             */
/*   Updated: 2023/10/23 10:43:51 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strappend(char *first, char *second, int rbytes)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	flen;

	i = 0;
	j = 0;
	flen = ft_strlen(first);
	newstr = malloc(sizeof(char) * (flen + (size_t)rbytes + 1));
	if (!newstr || flen + (size_t)rbytes + 1 < 1)
		return (ft_free(first));
	while (i < flen)
	{
		newstr[i] = first[i];
		i++;
	}
	while (j < (size_t)rbytes)
	{
		newstr[i + j] = second[j];
		j++;
	}
	newstr[i + j] = '\0';
	free (first);
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
	if (str)
		free (str);
	return (NULL);
}
