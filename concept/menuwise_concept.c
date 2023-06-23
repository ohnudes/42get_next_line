
#include "get_next_line.h"

t_buf	buff_filler(t_buf buffer)
{
	
}

char	*line_assambler(t_buf *buffer)
{
	char	*line;
	
	buffer->match = ft_strchr_t(&buffer);
	if (buffer->match == NULL)
		return (NULL);
	line = ft_substr_t(&buffer);
	if (!buffer->error)
		buf->content = ft_resize_t(&buffer);
	if (buffer->error)
	{
		line = NULL;
		return (NULL);
	}
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
	buffer.detected_flag = 0;
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
