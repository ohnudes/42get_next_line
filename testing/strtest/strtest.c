/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:10:56 by ohnudes           #+#    #+#             */
/*   Updated: 2023/07/13 10:42:35 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Notes
//
// Objective: to free a substring in another subfunction
// Interaction from: 
//	1. frame 0: original char *test
//	2. frame 1: char *test filled
//	3. frame 2: char *test passed as argument in &format
//		3.1. char *test is now char **test
//		3.2. char *test now has to be dereferencered
//		3.3. now to get the original *test clean, gotta clean from the same
//		memory. Otherwise what's freed is only a copy from the original memory.

#include <stdlib.h>
#include <stdio.h>

char	*strtest(char *test)
{
	char	*a;
	size_t	i;

	i = 0;
	a = "abcd";
	test = malloc(sizeof(char) * (10));
	while (i < sizeof(a))
	{
		test[i] = a[i];
		i++;
	}

	printf("%p  test == %s\n", test, test);
	return (test);
}

void	fr(char *test)
{
	//printf("%p  **test\n", test);
	//printf("%p  *test == %s\n", *test, *test);
	printf("%p  fr test == %s\n", test, test);
	free (test);
	//*test = NULL;
	test = NULL;
}

int	main (void)
{
	char	*test;

	printf("== INITIALIZE ==\n");
	test = NULL;
	printf("%p  test == %s\n", test, test);

	printf("== FILL ==\n");
	test = strtest(test);
	printf("%p  test == %s\n", test, test);

	printf("== FREE ==\n");
	fr(&*test);
	printf("%p  main *test == %s\n", test, test);
	printf("this one is supposed to be without content\n");

	return (0);
}
