#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*str_chr(char *s, int c);
char	*str_join(char *s1, char *s2);
char	*str_dup(char *s1);
char	*sub_str(char *s, size_t len);

#endif
