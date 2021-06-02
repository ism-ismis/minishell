#include "minishell.h"
#include "parser.h"

int	main(void)
{
	char		*line;
	t_str_list	*splited_lines;
	t_str_list	*tmp;
	int		i;
	t_node	*node;

	write(1, "minishell > ", 12);
	while (minishell_get_next_line(0, &line) == 1)
	{
		splited_lines = shell_split(line);
		splited_lines = var_expansion(splited_lines);
		tmp = splited_lines;
		while (tmp)
		{
			printf("%s\n", tmp->s);
			if (!ft_strcmp(tmp->s, "exit"))
				exit(0);
			tmp = tmp->next;
		}
		free(line);
		node = semicolon_node_creator(&splited_lines);
		write(1, "minishell > ", 12);
	}
	return (0);
}
