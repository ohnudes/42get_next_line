
#include "get_next_line.h"
#include <stdlib.h>
#include <sys/_types/_ssize_t.h>
#include <unistd.h>

char	*fill_buff(int fd) 
{
	ssize_t	bytes_read;
	char	*tmp;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	bytes_read = 1;

	// read
	while (bytes_read && !ft_strchr(tmp, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);

		// if tmp is filled and there's no end of line
		if (bytes_read == BUFFER_SIZE)
			tmp = prolongate_tmp(tmp);

		// protecting failed prolongate
		if (!tmp)
			return (NULL);
	}
	return (tmp);
}

void	node_ensambler(t_buf HEAD, char *str)
{
	size_t	i;
	t_buf	node;
	char	*content;
	char	*ref;


	ref = ft_strchr(str, '\n');
	i = 0;
	while (str)
	{
		if (ref)
		{
			while (str + i != ref)
				i++;
			content = malloc(sizeof(char) * (i + 1));
			// revisar la memoria! no puede ser solo en base a i!!
			if (!content)
				return (free_all);

			ft_memcpy(content, str, i);
			ft_lstadd_back(HEAD, ft_lstnew(content));
			if (HEAD->next == NULL)
				return (free_all);
			ref = ft_strchr((str + i), '\n');
		}
		if (!ref)
		{
			while (str[i])
				i++;
			content = malloc(sizeof(char) * (i + 1));
			if (!content)
				free_all;
			ft_memcpy(content, str, i);
			ft_lstadd_back(HEAD, ft_lstnew(content));
			content[i] = '\0';
		}
	}
}

char	*get_next_line(int fd)
{
	static	t_buf	*HEAD;
	char			*str;

	if (fd < 0)
		return (NULL);
	HEAD = NULL;
	if (!HEAD->next)
		str = fill_buff(fd);
	node_ensambler(HEAD, str);
	str = do_str(HEAD);
	return (str);

}


int	main(void)
{


}
