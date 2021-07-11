#ifndef UTILS_H
# define UTILS_H
# include "ft_history.h"

int		minishell_get_next_line(int fd, char **line, t_inter_list *ft_history);
void    error_numeric_argument(char *str);

#endif
