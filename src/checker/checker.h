#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 1 

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_line(char *s);
char	*get_rest(char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);

#endif
