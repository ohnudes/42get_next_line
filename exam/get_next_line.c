/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:21:40 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/25 18:29:43 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_buf
{
	char	*content;
	char	*match;
	char	error;
	int		rbytes;
}			t_buf;

static char	*fill_buffer(t_buf *buffer)
{
	char	*tmp;

	tmp = NULL;
	if (!tmp)
		return ();
	

}



static char	*deliver_line(t_buf *buffer)
{
	char	*line;
	int		match;

	line = NULL;
	if (buffer->match)
		line = ft_substr(buffer->content, match);
	else
	while (buffer->content[i] != '\n')
	match = ft_strchr(buffer->content, '\n');
	if (match)
		
	line = malloc(sizeof(char) * (match + 1));
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buf	buffer;
	char			*line;

	buffer = (t_buf){};
	line = NULL;
	if (fd < 2 || BUFFER_SIZE < 1)
		return (NULL);
	match = ft_strchr 
	if (buffer.content != NULL);
		line = deliver_line(&buffer);
	if (line == NULL)
	{
		match = fill_buffer(&buffer);
		if (!buffer.error)
			line = deliver_line(&buffer);
	}
	if (buffer.error)
	{
		buffer = clean_buffer(&buffer);
		return (NULL);
	}
	return (line);
}
