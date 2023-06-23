#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_strvoid(char	*str, int arglen)
{
	char	*ref;
	int		i;

	ref = str;
	if (ref)
	{
		i = 0;
		while (ref[i])
			ref[i] = '\0';
		free (ref);
		str = NULL;
	}
	printf("void function completed. Str freed\n");
}

int	main(int argc, char **argv)
{
	int		arglen;
	char	*str;
	int		i;

	i = 0;
	if (argc != 2)
		return (printf("invalid amount of arguments\n"));
	arglen = strlen(argv[1]);
	str = malloc(sizeof(char) * (arglen + 1));
	if (!str)
		return (printf("malloc error\n"));
	str[arglen] = '\0';
	printf("pre copy\n");
	while (i < arglen)
	{
		str[i] = argv[1][i];
		i++;
	}
	printf("Str filled: %s\n", str);
	ft_strvoid(&*str, arglen);
	if (str)
		printf("str result post ft_void %s\n", str);
	if (str)
		free (str);
	str = NULL;
	return (0);
}
