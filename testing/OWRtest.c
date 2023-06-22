/*
Objective:
Recreate env to understand Open/Read/Write functionment.

How to use:
1. string

Conclusions

1. For this test, BUFFER_SIZE dictates the sizes of reference, independent of
char formatting.
1.1. BUT! They will print in function of bytes-to-be-printed:
BUFFER_SIZE of 200 doesn't mean that it will actually write 200
chars, but all chars included under that range.
2. WRITE/READ are len dependant. That means that if a '\0'
is included in their referenced buffer, they will print if as
a null, and keep printing.
3. PRINTF will parse %s as a true C string: it will stop printing
when encountering the first null.
4. FD receives open result. But when said FD is used by write/read
it will keep an offset.
5. In result of (4), we can't use the same FD for both functions
unless we reset it, either closing and opening again or calling
another function that accomplishes the task.
6. Op/Rd/Wr have versioned functions that can improve compiling 
and execution time, but their analisis are outside of the scope
of this test.
7. nulltester.txt replaces \0 with ^@. I'm supposing there's some
kind of hex conversion? Anyways, it does not get printed
*/

#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*tmp;
	int		BUFFER_SIZE;
	char	test[200] = "uno\ndos\0 tres\n";
	int		fd;
	int		rbytes;
	int		wbytes;

	BUFFER_SIZE	= 18;
	printf("//// START ////\n");
	printf("\n");

	printf("//// OPEN ////\n");
	printf("buff_size = %d\n", BUFFER_SIZE);
	fd = open("nulltester.txt", O_RDWR);
	if (fd == -1)
		return (printf("error open %d\n", fd));
	printf("Open succesfull = %d\n", fd);
	printf("\n");

	printf("//// WRITE ////\n");
	wbytes = write(fd, test, 16);
	if (wbytes == -1)
		return (-1);
	close(fd);
	printf("test = %s\n", test);
	printf("Write succesfull = %d\n", wbytes);
	printf("\n");

	printf("//// MALLOC FOR TMP ////\n");
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (-1);
	printf("tmp succesfull\n");
	printf("\n");

	printf("//// READ ////\n");
	// open
	fd = open("nulltester.txt", O_RDWR);
	if (fd == -1)
		return (printf("error open %d\n", fd));
	printf("\n");
	// read
	rbytes = read(fd, tmp, BUFFER_SIZE);
	if (rbytes == -1)
	{
		free (tmp);
		return (-1);
	}
	tmp[rbytes] = '\0';
	printf("Read succesfull = %d\n", rbytes);
	printf("tmp contains =\n");
	write(1, tmp, BUFFER_SIZE);
	printf("\n");
	int	i = 0;
	while (i < BUFFER_SIZE)
	{
		tmp[i] = '\0';
		i++;
	}
	close (fd);
	free (tmp);
	printf("\n");
	printf("//// EOF ////\n");

	return (0);
}