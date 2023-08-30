/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:30:58 by nmaturan          #+#    #+#             */
/*   Updated: 2023/08/30 19:13:04 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, char set)
{
	char	*occurrence;

	if (!str)
		return (NULL);
	occurrence = (char *)str;
	while(*occurrence != set && *occurrence != '\0')
		occurrence++;
	if (*occurrence == set)
		return (occurrence);
	return (NULL);
}

char	*ft_free(char *str)
{
	if (*str)
		free (str);
	return (NULL);
}
