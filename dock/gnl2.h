#ifndef GNL_H
# define GNL_H

# define BUFFER_SIZE 1024

typedef struct s_bufdata
{
	char	*content;
	char	*line; 
	int		len; // EVERY MALLOC CONSIDERS +1

}			t_bufdata;

char	*get_next_line(int fd);

char	*buf_checker(t_bufdata *buf);
int		read_into_buff(t_bufdata *buf, int fd);
char	*line_assambler(t_bufdata *buf, int match);


#endif // !GNL_H
