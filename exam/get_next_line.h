/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:13:34 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/25 21:34:29 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_buffer
{
	char	*content;
	char	*error;
}			t_buf;

char	*get_next_line(int fd);

char	*ft_strjoin_t(char **s1, char **s2);
int		ft_strchr(char *str, char set);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);

#endif
