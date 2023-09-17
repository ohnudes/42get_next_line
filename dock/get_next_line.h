/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:30:45 by nmaturan          #+#    #+#             */
/*   Updated: 2023/09/17 11:48:20 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif 

# include <unistd.h>
# include <stdlib.h>

// main corpus
char	*get_next_line(int fd);
//static char		*fill_content(int rbytes, int fd, char **eol);
//static char		*find_eol(char	*eol, char *content, char *tmp, int rbytes);
//static char		*produce_line(char *content, char *eol);
//static char		*clean_content(char *content, char *eol);

// utils
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, char set);
char	*ft_strappend(char *first, char *second, int rbytes);
char	*ft_free(char *str);

#endif
