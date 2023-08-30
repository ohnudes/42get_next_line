/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:30:45 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/30 20:23:00 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif 

#include <unistd.h>
#include <stdlib.h>

// main corpus
char			*get_next_line(int fd);
static char		*fill_content(int rbytes, int fd, char **eol);
static char		*find_eol(char	*eol, char *content, char *tmp, int rbytes);
static char		*produce_line(char *content, char *eol);
static char		*clean_content(char *content, char *eol);

// utils
char	*ft_strchr(const char *str, char set);
char	*ft_strjoin(char *first, char *second);
char	*ft_free(char *str);

#endif
