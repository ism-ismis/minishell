#include "minishell.h"
#include "parser.h"

int	ft_env(t_node *node)
{
	int	i;

	(void)node;
	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
