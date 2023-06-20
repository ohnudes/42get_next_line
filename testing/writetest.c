#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* TESTING CASES:
 1. read with 0 rbytes
	-- returns 0, doesn't read
 2. read with -1 rbytes
	-- returns -1, -1 can be forced.
 3. how the freaking christ i can set a fd fml
 4.
 5.
 */

int	main(int argc, char **argv)
{
	char	*buf;
	int	i;

	buf = malloc(5);
	i = 0;
	while (i < 4)
	{
		buf[i] = i + '0';
		i++;
	}
	buf[5] = '\0';
	printf("check 1: %s\n", buf);
	int res = read(1, buf, 4);
	printf("check 2: %d\n", res);
	printf("check 3: %s\n", buf);
	free(buf);
	return (0);
}
