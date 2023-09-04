/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:25:50 by nmaturan          #+#    #+#             */
/*   Updated: 2023/09/04 17:57:13 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_content(char *content, char *eol)
{
	size_t	remaining_size;
	size_t	i;
	char	*newstr;
	char	*start;

	i = 0;
	start = eol + 1;
	if (*start == '\0')
		return (ft_free(content));
	remaining_size = ft_strlen(start);
	newstr = NULL;
	newstr = malloc(sizeof(char) * remaining_size + 1);
	if (!newstr)
		return (ft_free(content));
	newstr[remaining_size] = '\0';
	while (i < remaining_size)
	{
		newstr[i] = start[i];
		i++;
	}
	free (content);
	return (newstr);
}

static char	*produce_line(char *content, char *eol)
{
	char	*line;
	size_t	size;
	size_t	i;

	line = NULL;
	i = 0;
	if (!eol)
		return (NULL);
	if (*eol == '\n')
		size = eol - content + 1;
	else if (*eol == '\0')
		size = eol - content;
	else
		return (ft_free(content));
	line = malloc(sizeof(char) * size + 1);
	if (!line)
		return (ft_free(content));
	line[size] = '\0';
	while (i < size)
	{
		line[i] = content[i];
		i++;
	}
	return (line);
}

static char	*fill_content(int rbytes, int fd, char **eol)
{
	char	*tmp;
	char	*content;

	tmp = NULL;
	content = NULL;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	while (!*eol)
	{
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (rbytes == -1)
			return (ft_free(tmp));
		content = ft_strappend(content, tmp, rbytes);
		if (!content)
			return (ft_free(tmp));
		*eol = ft_strchr(content, '\n');
		if (*eol || rbytes == 0)
			break ;
	}
	free(tmp);
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;
	char		*eol;
	int			rbytes;

	line = NULL;
	eol = NULL;
	if (fd < 0 || read(fd, line, 0) < 0)
		return (NULL);
	rbytes = 0;
	if (!ft_strchr(content, '\n'))
		content = fill_content(rbytes, fd, &eol);
	else
		eol = ft_strchr(content, '\n');
	if (!content)
		return (NULL);
	line = produce_line(content, eol);
	if (line)
	{
		content = clean_content(content, eol);
		eol = NULL;
		return (line);
	}
	return (NULL);
}
