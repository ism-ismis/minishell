#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../srcs/libft/libft.h"
# include "../srcs/printf/printf.h"
# define GETCWD_SIZE 5

extern char **environ;

// extern int g_exit_code;

typedef struct s_node	t_node;

typedef struct s_str_list
{
	char				*s;
	struct s_str_list	*next;
}			t_str_list;

// int			minishell_get_next_line(int fd, char **line);
t_str_list	*shell_split(char *line);
int			is_separator(char c);
t_str_list	*var_expansion(t_str_list *splited_lines);
char		*remove_quotations(char *s);
char		*ft_strldup(const char *src, long len);
int			ft_echo(t_node *node);
int			ft_pwd(t_node *node);
int			ft_cd(t_node *node);
int			ft_export(t_node *node);
int			ft_unset(t_node *node);
int			ft_env(t_node *node);
void		ft_exit(t_node *node);
void		free_node(t_node *node);
char		*ft_getcwd(void);

#endif
