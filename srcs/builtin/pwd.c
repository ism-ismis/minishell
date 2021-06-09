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
		free(buf);
		i++;
		buf = malloc((GETCWD_SIZE * i + 1) * sizeof(char));
		if (!buf)//allocation error
			return (0);
	}
	return (buf);
}

int	ft_pwd(t_node *node)
{
	ft_printf("%s\n", ft_getcwd());
	return (1);
}
