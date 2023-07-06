/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:28:49 by nmaturan          #+#    #+#             */
/*   Updated: 2023/07/06 18:11:53 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	 i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// strchr checks for index of match, not the amount of chars in!
int		ft_strchr(char *str, char set)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != set)
		i++;
	if (str[i] != set)
		return (-1);
	return (i);
}

// function creates handles malloc error
char	*ft_strjoin(char *content, char *tmp)
{
	int		len_s1;
	int		len_s2;
	char	*newcontent;
	int		i;

	if (content == NULL && tmp == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(content);
	len_s2 = ft_strlen(tmp);
	newcontent = malloc(len_s1 + len_s2 + 1);
	if (newcontent == NULL)
	{
		free (content);
		return (NULL);
	}
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			newcontent[i] = content[i];
		if (i < len_s2)
			newcontent[i + len_s1] = tmp[i];
		i++;
	}
	newcontent[len_s1 + len_s2] = '\0';
	free (content);
	return (newcontent);
}


void	read_content(char **str, int fd)
{
	char	*tmp;
	int		match;
	int		rbytes;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return ;
	rbytes = 1;
	match = -1;
	while (rbytes != -1)
	{
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (rbytes != -1)
		{
			match = ft_strchr(tmp, '\n');
			*str = ft_strjoin(*str, tmp);
		}
		if (match >= 0 || rbytes == 0)
		{
			free (tmp);
			return ;
		}
		if (*str == NULL)
			return ;
	}
}

char	*produce_line(char **content)
{
	char	*line;
	int		match;
	size_t	i;

	match = ft_strchr(*content, '\n') + 1;
	if (match == -1)
		match = ft_strlen(*content);
	line = malloc(sizeof(char) * (match + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < match - 1)
	{
		line[i] = (*content)[i];
		i++;
	}
	line[match] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char static *content = {0};
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!content || ft_strchr(content, '\n') == -1)
		read_content(&content, fd);
	if (content != NULL)
		line = produce_line(&content);
	if (!line)
		free (content);
	return (line);
}
