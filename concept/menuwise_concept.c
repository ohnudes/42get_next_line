
#include "get_next_line.h"

t_buf	buff_filler(t_buf buffer)
{
	
}

char	*line_assambler(t_buf *buffer)
{
	char	*line;
	
	buffer->match = ft_strchr_t(buffer);
	if (buffer->match == 0)
		return (NULL);
	line = ft_substr_t(buffer->content, buffer->match, buffer->error);
	if (!buffer->error)
		buffer->content = ft_resize_t(buffer->content, buffer->match);
	if (buffer->error)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buf	buffer;
	char			*line;

	if (fd < 0)
		return (NULL);
	if (!buffer.content)
		buffer = (t_buf){};
	while (!line && !buffer.error)
	{
		if (buffer.content && !buffer.error)
			line = line_assambler(&buffer);
		if (!buffer.error)
			buffer = buff_filler(buffer);
	}
	if (buffer.error)
		return (NULL);
	return (line);
}
