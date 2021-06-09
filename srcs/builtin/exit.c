#include "minishell.h"
#include "parser.h"

void	free_node(t_node *node)
{
	int	i;

	if (node)
	{
		if (node->lhs)
			free_node(node->lhs);
		if (node->rhs)
			free_node(node->rhs);
		i = 1;
		while (node->tokens[i])
			free(node->tokens[i++]);
		free(node->tokens);
		free(node->redirect_info);
		//free(node->cm_content);
	}
}

int	ft_exit(t_node *node)
{
	free_node(node);
	free(node);
	system("leaks minishell");
	exit(0);
	return (1);
}
