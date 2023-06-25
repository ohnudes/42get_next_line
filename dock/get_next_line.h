/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:06:19 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/25 17:13:57 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buf
{
	char		*content;
	char		error;
	size_t		len;
	int			fd;
}				t_buf;

char	*get_next_line(int fd);

int		ft_strchr(char *content, char set);
char	*ft_substr(char *content, size_t match);
char	*ft_strjoin(char *s1, char *s2);

#endif
#endif
