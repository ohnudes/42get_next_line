
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

	BUFFER_SIZE	= ft_strlen(test);
	fd = open("nulltester.txt", O_RDWR);
	if (fd == -1)
		return (printf("error open %d\n", fd));
	wbytes = write(fd, test, 16);
	if (wbytes == -1)
		return (-1);
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (-1);
	rbytes = read(fd, tmp, BUFFER_SIZE);
	if (rbytes == -1)
	{
		free (tmp);
		return (-1);
	}
	tmp[rbytes] = '\0';
	int	i = 0;
	while (i < BUFFER_SIZE)
	{
		tmp[i] = '\0';
		i++;
	}
	close (fd);
	free (tmp);
	return (0);
}
