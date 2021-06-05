#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"
# include "../srcs/printf/printf.h"

typedef struct s_node t_node;

typedef struct s_str_list
{
	char				*s;
	struct s_str_list	*next;
}				t_str_list;

int			minishell_get_next_line(int fd, char **line);
t_str_list	*shell_split(char *line);
int			is_separator(char c);
t_str_list	*var_expansion(t_str_list *splited_lines);
char		*remove_quotations(char *s);
char		*ft_strldup(const char *src, long len);
int			echo(t_node *node);

#endif
