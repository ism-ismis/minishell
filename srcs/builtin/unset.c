#include "minishell.h"
#include "parser.h"

int	ft_unset(t_node *node)
{
	int	i;
	int	tokenlen;
	int	envlen;

	tokenlen = ft_strlen(node->tokens[1]);
	envlen = 0;
	while (environ[envlen])
		envlen++;
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(node->tokens[1], environ[i], tokenlen)
			&& environ[i][tokenlen] == '=')
			break ;
		i++;
	}
	if (environ[i])
	{
		free(environ[i]);
		memmove(environ + i, environ + i + 1,
			(envlen - i + 1) * sizeof(char *));
	}
	return (0);
}
