/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:25:50 by nmaturan          #+#    #+#             */
/*   Updated: 2023/09/07 17:24:45 by nmaturan         ###   ########.fr       */
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
	newstr = NULL;
	remaining_size = 0;
	if (eol && eol + 1)
	{
		start = eol + 1;
		remaining_size = ft_strlen(start);
	}
	else if (*content == '\0')
		return (ft_free(content));
	newstr = malloc(sizeof(char) * (remaining_size + 1));
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
	size = 0;
	if (!eol)
		eol = content + ft_strlen(content);
	size = eol - content + 1;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	line[size] = '\0';
	while (i < size)
	{
		line[i] = content[i];
		i++;
	}
	if (*line == '\0')
		return (ft_free(line));
	return (line);
}

static char	*fill_content(char *content, int rbytes, int fd, char **eol)
{
	char	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ft_free(content));
	tmp[BUFFER_SIZE] = '\0';
	while (!*eol)
	{
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (rbytes > 0)
			content = ft_strappend(content, tmp, rbytes);
		if (rbytes == -1 || !content)
		{
			ft_free(content);
			return (ft_free(tmp));
		}
		*eol = ft_strchr(content, '\n');
		if (rbytes == 0 || rbytes < BUFFER_SIZE)
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
	if (fd < 0)
		return (NULL);
	rbytes = 0;
	eol = ft_strchr(content, '\n');
	if (!eol)
		content = fill_content(content, rbytes, fd, &eol);
	if (!content || *content == '\0')
		return (ft_free(content));
	line = produce_line(content, eol);
	if (!line && content)
		return (ft_free(content));
	content = clean_content(content, eol);
	return (line);
}
