/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:07:45 by ohnudes           #+#    #+#             */
/*   Updated: 2023/07/23 02:23:38 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

static char	*fill_storage(int fd, char *storage)
{
	char			*tmp;
	ssize_t			rbytes;	

	tmp = NULL;
	rbytes = 1;
	while (rbytes > 0)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (!tmp || rbytes == -1)
			return (ft_free(storage));
		tmp[BUFFER_SIZE] = '\0';
		storage = ft_strjoin(storage, tmp);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(storage, '\n') != -1)
			break ;
	}
	return (storage);
}

static char	*separate_lines(char *line, char **storage)
{
	int	match;
	int	storage_len;

	storage_len = ft_strlen(*storage);
	match = ft_strchr(*storage, '\n');
	if (match == -1 || match + 1 == storage_len)
	{
		line = *storage;
		*storage = ft_free(*storage);
	}
	else
	{
		line = ft_substr(*storage, 0, match + 1);
		if (!line)
			free (*storage);
		else
			*storage = ft_substr(*storage, match + 1, storage_len - match);
		if (!*storage)
			*storage = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (!storage || (storage && ft_strchr(storage, '\n') == -1))
		storage = fill_storage(fd, storage);
	if (storage)
		line = separate_lines(line, &storage);
	if (!*line)
		line = ft_free(line);
	return (line);
}


int	main(void)
{
	int		fd;
	int		rbytes;
	char	*line;

	line = NULL;
	rbytes = 10;
	fd = open("test.txt", O_RDWR);
	line = get_next_line(fd);
	while (rbytes--)
	{
		printf("%p  line\n", line);
		printf("==== CONTENT ====\n");
		printf("%s", line);
		printf("\n==== END OF CONTENT ====\n");
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (0);
}
