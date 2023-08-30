/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:25:50 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/30 20:24:03 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*clean_content(char *content, char *eol)
{
	size_t	remaining_size;
	char	*newstr;

	if (*eol == '\0')
		return (ft_free(content));
	remaining_size = 0;
	newstr = NULL;
	remaining_size = content + sizeof(content) - eol;
	newstr = malloc(sizeof(char) * remaining_size + 1);
	if (!newstr)
		return (ft_free(content));
	newstr[remaining_size] = '\0';
	while (remaining_size + 1 > 0)
		newstr[remaining_size + 1] = *(eol + 1 + remaining_size);
	free (content);
	return (newstr);
}

static char	*produce_line(char *content, char *eol)
{
	char	*line;

	line = NULL;
	if (*eol == '\n')
	{
		line = malloc(sizeof(char) * (eol - content) + 1);
		*(line + sizeof(line) - 1) = '\0';
	}
	else if (*eol == '\0')
		line = malloc(sizeof(char) * (eol - content));
	else
	{
		printf("\nerror of eol precission\n");
		return (ft_free(content));
	}
	while (content <= eol)
		*line++ = *content++;
	return (line);
}

static char	*find_eol(char	*eol, char *content, char *tmp, int rbytes)
{
	if (rbytes == 0)
		eol = content + sizeof(content) - 1;
	else if (eol)
		eol = content + (sizeof(content)) - 1 - (sizeof(tmp)) + (eol - tmp);
	else
		return (NULL);
	return (eol);
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
	while (!eol)
	{
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (rbytes == -1)
			return (ft_free(tmp));
		*eol = ft_strchr(tmp, '\n');
		content = ft_strjoin(content, tmp);
		if (!content)
			return (ft_free(tmp));
		if (*eol || rbytes == 0)
			break ;
	}
	*eol = find_eol(*eol, content, tmp, rbytes);
	free(tmp);
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;
	char		*eol;
	int			rbytes;

	if (fd < 0 || read(fd, line, 0) < 0)
		return (NULL);
	eol = NULL;
	line = NULL;
	rbytes = 0;
	if (!ft_strchr(content, '\n'))
		content = fill_content(rbytes, fd, &eol);
	if (content)
		return (NULL);
	line = produce_line(content, eol); 
	if (line)
	{
		content = clean_content(content, eol);
		return (line);
	}
	return (NULL);
}
