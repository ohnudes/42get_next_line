
#include "get_next_line.h"

static char	*buff_filler(t_buf *buffer, int fd)
{
	char	*tmp;
	char	error;
	int		rbytes;

	rbytes = 1;
	while (rbytes > 0)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tmp)
			break;
		tmp[BUFFER_SIZE] = '\0';
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (rbytes != -1 && !ft_strchr(tmp, '\n'))
			tmp = ft_strjoin(&buffer, tmp);
		if (tmp && rbytes == 0 && !error)
		{
			buffer->len = ft_strchr(buffer->content, '\0');
			return (tmp);
		}
	}
	buffer->error = -1;
	return (NULL)
}

static char	*line_assambler(t_buf *buffer)
{
	char	*content;
	char	*line;
	size_t	match;
	
	content = buffer->content;
	match = ft_strchr(content, '\n');
	if (match)
		line = ft_substr_t(content, match);
	if (line)
	{
		match = ft_strchr(content[match], '\0');
		content = ft_substr_t(content[match], match);
		if (content)
		{
			free (buffer->content); 
			buffer->content = content;
			if (!error)
				return (line);
		}
	}
	buffer->error = -1;
	return (NULL);
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
			buffer.content = buff_filler(&buffer, fd);
	}
	if (buffer.error)
	{
		free_sbuf(&buffer);
		return (NULL);
	}
	return (line);
}
