/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:00:34 by ohnudes           #+#    #+#             */
/*   Updated: 2023/06/22 12:49:51 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_buflen
{
	char	*content;
	char	*line; 
	int		len; // EVERY MALLOC CONSIDERS +1

}			t_bufdata;

char	*line_assambler(t_bufdata *buf, int match)
{
	char	*line;
	char	*eol;

	eol = buf->content;
	line = NULL;
	if (!eol[match])
		line = malloc(sizeof(char) * (buf->len + 1));
	else
		line = malloc(sizeof(char) * (match + 1));
	if (!line)
		return (NULL);
	line = ft_substr(buf->content, match); // handles '\0' termination
	if (eol[match])
		buf->content = ft_substr((buf->content + match), buf->len);
	return (line);
}

int	read_into_buff(t_bufdata *buf, int fd)
{
	char	*tmp;
	int		match;
	int		rbytes;

	match = 0;
	while (!match)
	{
		tmp = NULL;
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tmp)
			return NULL;
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (rbytes == -1)
			return NULL;
		tmp[BUFFER_SIZE] = '\0';
		&buf = ft_strjoin(buf, tmp, rbytes); // checker comes after the strjoin.
		match = ft_strchr(&buf); // checks buf + rbytes for reference.
		free (tmp);
	}
	return (match);
}

char	*buf_checker(t_bufdata *buf)
{
	char	*str;
	char	*newbuf;
	int		i;
	int		j;

	if (!buf->content)
		return (NULL);
	str = buf->content;
	i = 0;
	while (i < buf->len && str[i] != '\n')
		i++;
	if (i < buf->len) // SUBSTR
	{
		str = NULL;
		str = malloc(sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
		j = i;
		str[i--] = '\0';
		while (i >= 0)
		{
			str[i] = *(buf->content + i);
			i--;
		}
		newbuf = malloc(sizeof(char) * (buf->len - j + 1));
		while (j < buf->len)
			newbuf[i++] = *(buf->content + j++);
		newbuf[i] = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static t_bufdata	buf; // static buffer
	char				*line; // returned line which ends at '\n'
	int					*match; // first '\n' ocurrence

	if (fd < 0)
		return (NULL);
	line = NULL;
	match = NULL;
	line = buf_checker(&buf);
	if (!line)
	{
		while (!match)
			match = read_into_buff(&buf, fd);
		line = line_assambler(&buf, match); // line can be null
	}
	return (line);
}

int	main(void)
{

	return (0);
}
