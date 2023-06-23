#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buf
{
	char		**storage;
	char		*content;
	char		*error;
	size_t		*match;
	size_t		len;
	int			fd;
}				t_buf;

char	*get_next_line(int fd);
char	*line_assambler(t_buf *buffer);
t_buf	buff_filler(t_buf buffer);	

size_t	ft_strchr_t(t_buf *buffer);
char	*ft_substr_t(char *buffer, size_t *match, char *error);
char	*ft_resize_t(char *content, size_t *match);

#endif
