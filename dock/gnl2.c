/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:00:34 by ohnudes           #+#    #+#             */
/*   Updated: 2023/06/21 22:55:25 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

typedef struct s_buflen
{
	char	*content;
	int		len; // EVERY MALLOC CONSIDERS +1

}			t_bufdata;

char	*line_assambler();

char	*read_into_buff();

char	*buf_checker(t_bufdata *buf)
{
	char	*str;
	int		i;

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
		str[i--] = '\0';
		while (i >= -1)
		{
			str[i] = *(buf->content + i);
			i--;
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static t_bufdata	buf; // static buffer
	char				*line; // returned line which ends at '\n'
	char				*ref; // first '\n' ocurrence

	if (fd < 0)
		return (NULL);
	line = buf_checker(&buf);
	if (!line)
		while (!ref)
			ref = read_into_buff(&buf, fd);
	line = line_assambler(ref, &buf);
	return (line);
}

int	main(void)
{

	return (0);
}
