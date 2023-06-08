#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>


typedef struct s_buf
{
	char			*content;
	struct s_buf	*next;
}					t_buf;


char	*get_next_line(int fd);
char	*get_next_line_utils(int fd);

size_t	ft_strlen(char *buffer);
void	ft_lstaddback(t_buf HEAD, t_buf tmp);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
