/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:06:11 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/26 17:10:32 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_free(char **buffer);
char	*ft_strjoin_t(char *s1, char *s2);
char	*ft_substr(char **str, unsigned int start, size_t len);
int		ft_strchr(const char *str, char set);
size_t	ft_strlen(const char *str);

#endif
