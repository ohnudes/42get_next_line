
#include "get_next_line.h"
#include <stdlib.h>

t_buf	*free_all(t_buf	**t_HEAD, char *str)
{
	t_buf	*ref;
	char	*buf;
	size_t	i;

	ref = *t_HEAD;
	while (ref)
	{
		buf = ref->content;
		if (buf)
		{
			while (buf)
				i++;
			while (buf[i--] != '\0')
				buf[i] = '\0';
		}
		free (ref->content);
		*t_HEAD = ref->next;
		ref->next = NULL;
		ref = *t_HEAD;
		if (!ref)
			free (ref);
	}
	return ((void *)NULL);
}

char	*node_ensambler(t_buf **t_HEAD, char *str)
{
	t_buf	*t_new_node;
	t_buf	*t_last;

	t_new_node = ft_lstnew(str); // HACER STRDUP DENTRO DE LSTNEW!
	if (!t_new_node)
		return ((char *)free_all(t_HEAD, str));
	if (t_HEAD == NULL)
		*t_HEAD = t_new_node;
	else
	{
		t_last = *t_HEAD;
		while (t_last->next)
			t_last = t_last->next;
		t_last->next = t_new_node;
	}
	return (str);
}

t_buf	*fill_buff(int fd, t_buf **t_HEAD) 
{
	ssize_t	bytes_read;
	char	*tmp;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (free_all(t_HEAD, tmp));
	tmp[BUFFER_SIZE] = '\0';
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_all(t_HEAD, tmp));
		if (ft_strchr(tmp, '\n'))
		{
			tmp = node_ensambler(t_HEAD, tmp);
			free (tmp);
			return (*t_HEAD);
		}
		tmp = node_ensambler(t_HEAD, tmp);
	}
	free (tmp);
	return (*t_HEAD);
}

char	*do_str(t_buf *t_HEAD)
{
	t_buf	*t_iter;
	char	*str;

	t_iter = t_HEAD;
	while (t_iter && t_iter->next)
	{
		ft_strjoin(t_iter->content, const char *s2);
	}	
	return (str);
}

char	*get_next_line(int fd)
{
	static	t_buf	*t_HEAD;
	char			*str;

	if (fd < 0)
		return (NULL);
	t_HEAD = NULL;
	if (!t_HEAD)
		t_HEAD = fill_buff(fd, &t_HEAD);
	if (!t_HEAD)
		return (NULL);
	str = do_str(t_HEAD);
	return (str);
}
