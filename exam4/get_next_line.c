/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:07:45 by ohnudes           #+#    #+#             */
/*   Updated: 2023/07/13 15:07:05 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/_types/_null.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

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

char	*fill_storage(int fd, char *storage)
{
	char			*tmp;
	ssize_t			rbytes;	

	tmp = NULL;
	rbytes = 1;
	while (rbytes > 0)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (!tmp || rbytes == -1)
			return (ft_free(storage));
		tmp[BUFFER_SIZE] = '\0';
		storage = ft_strjoin(storage, tmp);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(storage, '\n') != -1)
			break;
	}
	return (storage);
}

// casos:
// 1. devuelve parte de storage (match + 1 < storage_len) 
//	\---> line filled, storage = storage_len - line_len
// 2. devuelve todo storage 
//  \---> line = *storage, *storage = NULL;
char	*separate_lines(char *line, char **storage)
{
	int	match;
	int storage_len;

	storage_len = ft_strlen(*storage);
	match = ft_strchr(*storage, '\n');
	if (match == -1 || match + 1 == storage_len)
	{
		line = *storage;
		*storage = ft_free(*storage);
	}
	else
	{
		line = ft_substr(*storage, 0, match + 1);
		if (!line)
			free (*storage);
		else
			*storage = ft_substr(*storage, match + 1, storage_len - match);
		if (!*storage)
			*storage = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	static	*storage;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (!storage)
		storage = NULL;
	if (!storage || (storage && ft_strchr(storage, '\n') == -1))
		storage = fill_storage(fd, storage);
	if (storage)
		line = separate_lines(line, &storage);
	if (*line == '\0')
		line = ft_free(line);
	return (line);
}

int	main(void)
{
	int		fd;
	int		rbytes;
	char	*line;

	line = NULL;
	rbytes = 1;
	fd = open("test.txt", O_RDWR);
	line = get_next_line(fd);
	if (line)
	{
		while (line != NULL)
		{
			rbytes = printf("%p  line\n", line);
			rbytes = printf("==== CONTENT ====\n");
			rbytes = printf("%s", line);
			rbytes = printf("\n==== END OF CONTENT ====\n");
			line = get_next_line(fd);
		}
	}
	else
		printf("\nreading ended\n");
	free (line);
	close (fd);
	return (0);
}
