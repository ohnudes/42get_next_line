/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:00:57 by nmaturan          #+#    #+#             */
/*   Updated: 2023/07/01 11:19:44 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer)
{
	free (buffer);
	buffer = NULL;
	return (buffer);
}

static char	*read_to_buffer(char *buffer, int fd)
{
	char	*tmp;
	int		rbytes;
	int		match;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\n';
	match = -1;
	rbytes = 1;
	while (match < 0 || rbytes > 0)
	{
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (rbytes > 0)
		{
			match = ft_strchr(tmp, '\n');
			buffer = ft_strjoin_t(&*buffer, tmp);
		}
		if (!buffer || rbytes == -1)
		{
			free (tmp);
			return (NULL);
		}
	}
	free (tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer = {0};
	char			*line;
	int				match;

	match = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if ((buffer && ft_strchr(buffer, '\n') < 0) || !buffer)
		buffer = read_to_buffer(buffer, fd);
	if (!buffer)
		return (ft_free(buffer));
	match = ft_strchr(buffer, '\n');
	if (match < 0)
		match = ft_strlen(buffer);
	line = ft_substr(buffer, 0, match);
	if (!line && buffer)
		return (ft_free(buffer));
	buffer = ft_substr(buffer, ft_strlen(line), ft_strlen(buffer) - match);
	return (line);
}
