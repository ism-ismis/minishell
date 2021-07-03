#include "minishell.h"
#include "parser.h"

char	*ft_getcwd(void)
{
	char	*buf;
	int		i;

	buf = malloc((GETCWD_SIZE + 1) * sizeof(char));
	if (!buf)//allocation error
		return (0);
	i = 1;
	while (!getcwd(buf, GETCWD_SIZE * i))
	{
		i++;
		free(buf);
		buf = malloc((GETCWD_SIZE * i + 1) * sizeof(char));
		if (!buf)//allocation error
			return (0);
	}
	return (buf);
}

int	ft_pwd(t_node *node)
{
	char	*cwd;

	(void)node;
	cwd = ft_getcwd();
	//OLDPWD=PWD
	//PWD=cwd
	ft_putendl_fd(cwd, 1);
	free(cwd);
	return (0);
}
