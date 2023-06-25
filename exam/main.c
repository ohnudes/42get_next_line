/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:24:06 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/25 21:41:54 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char *str;
	
	fd = 0;
	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (1);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (str != NULL)
			free (str);
	}
	return (0);
}
