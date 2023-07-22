/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:50:48 by ohnudes           #+#    #+#             */
/*   Updated: 2023/07/13 16:50:55 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free (str);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char	*str, char set)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != set)
		i++;
	if (str[i] == set)
		return (i);
	return (-1);
}

char	*ft_substr(char *str, unsigned int start, size_t str_len)
{
	char	*line;
	size_t	len;
	size_t	i;

	i = -1;
	if (ft_strlen(str + start) < str_len)
		len = ft_strlen(str + start);
	else
		len = str_len - (start + 1);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (ft_free(str));
	while (++i < len)
		line[i] = str[start + i];
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*s3;
	int		i;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = malloc(len_s1 + len_s2 + 1);
	if (s3 == NULL)
		return (ft_free(s1));
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			s3[i] = s1[i];
		if (i < len_s2)
			s3[i + len_s1] = s2[i];
		i++;
	}
	s3[len_s1 + len_s2] = '\0';
	free (s1);
	return (s2);
}

