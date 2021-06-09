#include "minishell.h"
#include "parser.h"

int	optional_new_line(t_node *node)
{
	int	i;
	int	j;
	int	new_line;

	new_line = 1;
	i = 1;
	if (!ft_strncmp(node->tokens[i], "-n", 2))
	{
		j = 2;
		while (node->tokens[i][j] == 'n')
			j++;
		if (!node->tokens[i][j])
		{
			new_line = 0;
			i++;
		}
	}
	return (new_line);
}

int	ft_echo(t_node *node)
{
	int	i;
	int	new_line;

	new_line = optional_new_line(node);
	i = 1;
	if (!new_line)
		i++;
	while (node->tokens[i])
	{
		ft_printf("%s", node->tokens[i]);
		if (node->tokens[++i])
			ft_printf(" ");
	}
	if (new_line)
		ft_printf("\n");
	return (1);
}
