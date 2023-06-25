/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:29:57 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/25 22:22:47 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buffer(t_buf *buffer, int fd)
{
	char	*tmp;
	int		rbytes;

	rbytes = 1;
	while (rbytes != 0)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		rbytes = read(fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE] = '\0';
		if (ft_strchr(tmp, '\n'))
		{
			buffer->content = ft_strjoin_t(&buffer->content, &tmp); 
			break ;	
		}
		buffer->content = ft_strjoin_t(&buffer->content, &tmp); 
	}
	if (tmp != NULL)
		free (tmp);
	return (buffer->content);
}

static char	*deliver_line(t_buf *buffer)
{
	char	*line;
	int		match;
	size_t	len;
	
	line = NULL;
	len = 0;
	len = ft_strlen(buffer->content);
	match = ft_strchr(buffer->content, '\n');
	if (match < 0)
	{
		line = ft_substr(buffer->content, 0, ft_strlen(buffer->content));
		return (buffer->content);
	}
	line = ft_substr(buffer->content, 0, len);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buf	buffer;
	char			*line;

	line = NULL;
	buffer = (t_buf){};
	buffer.content = fill_buffer(&buffer, fd);
	line = deliver_line(&buffer);
	return (line);
}
