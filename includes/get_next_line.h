#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

int		get_next_line(int fd, char **line);
int		has_nl(char *str);
char	*join_str(const char *str1, const char *str2);
size_t	ft_len(const char *s);
void	*ft_memory(void *dst, const void *src, size_t len);

#endif
