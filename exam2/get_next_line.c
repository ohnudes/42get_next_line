/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:00:57 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/26 16:10:51 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static char	*read_to_buffer(t_stor *buffer, int fd)
{
	char	*tmp;

	tmp = NULL;
	while (!line)

}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	size_t			

	if (fd < 0 || BUFFER_SIZE < 0) 
		return (NULL);	
	match = ft_strchr(buffer, '\n');
	if ((buffer && !match) || !buffer)
		buffer = read_to_buffer(&buffer, fd);
	if (!buffer)
		return (ft_free(&buffer))
	line = ft_substr(&buffer, 0, match);
	buffer = ft_substr(buffer, match, len);  
	return (line);
}
