#include "minishell.h"
#include "parser.h"

int	ft_cd(t_node *node)
{
	chdir(node->tokens[1]);
	return (1);
}
