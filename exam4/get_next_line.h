/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:43:55 by ohnudes           #+#    #+#             */
/*   Updated: 2023/07/23 01:56:43 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*ft_free(char *str);
size_t	ft_strlen(char *str);
int		ft_strchr(char	*str, char set);
char	*ft_substr(char *str, unsigned int start, size_t str_len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
