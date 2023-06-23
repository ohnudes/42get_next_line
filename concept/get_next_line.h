#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

typedef struct s_buf
{
	char		**storage;
	char		*content;
	char		*match;
	char		detected_flag;
	char		error;
	int			len;
	int			fd;
}				t_buf;

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*line_assambler(t_buf *buffer);
t_buf	buff_filler(t_buf buffer);	

char	*ft_strchr_t(t_buf *buffer);
char	*ft_substr_t(t_buf *buffer);
char	*ft_resize_t(t_buf *buffer);

#endif
