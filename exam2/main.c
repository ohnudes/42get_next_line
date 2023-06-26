/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:30:11 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/26 18:38:52 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/fcntl.h>

int	main(void)
{
	int	fd;
	char *str;
	
	fd = 0;
	fd = open("test.txt", O_RDWR);
	str = NULL;
	while (fd > 0)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (str != NULL)
			free (str);
		if (!str)
			close (fd);
	}
	return (0);
}
