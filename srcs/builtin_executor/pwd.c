#include "minishell.h"
#include "parser.h"

int	ft_pwd(t_node *node)
{
	char	*buf;
	int		i;

	buf = malloc((GETCWD_SIZE + 1) * sizeof(char));
	if (!buf)//allocation error
		return (0);
	i = 1;
	while (!getcwd(buf, GETCWD_SIZE * i))
	{
		free(buf);
		i++;
		buf = malloc((GETCWD_SIZE * i + 1) * sizeof(char));
		if (!buf)//allocation error
			return (0);
	}
	ft_printf("%s\n", buf);
	return (1);
}
