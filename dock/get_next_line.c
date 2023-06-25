/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:07:33 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/25 17:08:44 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*buff_filler(t_buf *buffer, int fd)
{
	char	*tmp;
	int		match;
	int		rbytes;

	match = 0;
	rbytes = 0;
	while (match != -1 && rbytes != -1)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (tmp)
		{
			tmp[BUFFER_SIZE] = '\0';
			rbytes = read(fd, tmp, BUFFER_SIZE);
			if (rbytes != -1)
				match = ft_strchr(tmp, '\n');
			if (rbytes != -1)
				buffer->content = ft_strjoin(buffer->content, tmp);
			if ((match != -1 || rbytes == 0) && tmp != NULL)
				return (tmp);
		}
		if (!tmp)
			break ;
	}
	free (tmp);
	free (buffer->content);
	buffer->error = -1;
	return (NULL);
}

static char	*line_assambler(t_buf *buffer)
{
	char	*content;
	char	*line;
	size_t	match;

	content = buffer->content;
	match = ft_strchr(content, '\n');
	if (match)
		line = ft_substr(content, match);
	if (line != NULL)
	{
		match = ft_strchr(content + match, '\0');
		content = ft_substr(content + match, match);
		if (content != NULL)
		{
			free (buffer->content);
			buffer->content = content;
			return (line);
		}
	}
	free (content);
	free (buffer->content);
	return (NULL);
}

// possible errors
// 1. malloc at strjoin or substr -> return cascade NULL
// 2. invalid read

char	*get_next_line(int fd)
{
	static t_buf	buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffer.content)
		buffer = (t_buf){};
	while (!line && !buffer.error)
	{
		if (buffer.content && !buffer.error)
			line = line_assambler(&buffer);
		if (!buffer.error)
			buffer.content = buff_filler(&buffer, fd);
	}
	if (buffer.error)
		return (NULL);
	return (line);
}
