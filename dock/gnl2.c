/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:00:34 by ohnudes           #+#    #+#             */
/*   Updated: 2023/06/21 22:24:45 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (buf->content)
	{
		str = buf->content;
		str[buf->len] = '\n';
		while (*str != '\n')
			str++;
		if (&*str != &*(buf->content + buf->len)) // diff of both pointers
					
	}
	str = NULL;
	return (NULL);
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
