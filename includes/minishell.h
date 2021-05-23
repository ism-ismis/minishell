#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"

int		get_next_line(int fd, char **line);
char	**shell_split(char *line);
char	*ft_strldup(const char *src, long len);

#endif
