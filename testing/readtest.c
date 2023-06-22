
#include <string.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	char	*tmp;
	int		BUFFER_SIZE;
	char	test[] = "uno\ndos";
	int		fd;
	int		rbytes;
	int		wbytes;

	wbytes = 0;
	rbytes = 1;
	printf("//// START ////\n");
	printf("\n");

	printf("//// OPEN ////\n");
	BUFFER_SIZE	= ft_strlen(test);
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
	rbytes = read(fd, tmp, BUFFER_SIZE);
	if (rbytes == -1)
	{
		free (tmp);
		return (-1);
	}
	tmp[rbytes] = '\0';
	printf("Read succesfull = %d\n", rbytes);
	printf("tmp contains = %s\n", tmp);
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
