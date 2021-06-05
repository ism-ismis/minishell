#include "parser.h"
#include "minishell.h"

int	echo(t_node *node)
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
