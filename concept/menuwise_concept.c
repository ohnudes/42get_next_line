
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
		tmp[BUFFER_SIZE] = '\0';
		if (!tmp)
			break;
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (!ft_strchr(tmp, '\n') && rbytes != -1)
			tmp = ft_strjoin(&buffer, tmp);
		if (tmp && rbytes != -1 && !error)
			return (tmp);
	}
	error = 0;
	buffer->error = error;
	return (NULL)
}

static char	*line_assambler(t_buf *buffer)
{
	char	*content;
	char	*line;
	char	error;
	size_t	match;
	
	error = 0;
	buffer->error = error;
	*content = buffer->content;
	
	match = ft_strchr(content, '\n'); // returns either \n or \0
	if (match)
		line = ft_substr_t(&error, content, match);
	if (!error && line)
	{
		content = ft_downsize_t(buffer, match);
		return (line);
	}
	error = -1;
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
