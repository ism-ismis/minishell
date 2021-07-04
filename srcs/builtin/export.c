#include "minishell.h"
#include "parser.h"

char	*ft_setenv(char *s)
{
	int	len;

	len = 0;
	if (s)
		while (s[len] && s[len] != '=')
			len++;
	if (!s[len])
		return (ft_strjoin(s, "="));
	return (ft_strdup(s));
}

int	ft_keylen(char *s)
{
	int	len;

	len = 0;
	if (s)
		while (s[len] && s[len] != '=')
			len++;
	return (len);
}

int	ft_export(t_node *node)
{
	int	envlen;
	int	keylen;
	int	i;

//still don't expand ', "
	keylen = ft_keylen(node->tokens[1]);
	envlen = 0;
	while (environ[envlen])
		envlen++;
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(node->tokens[1], environ[i], keylen)
			&& environ[i][keylen] == '=')
			break ;
		i++;
	}
	if (environ[i])
		environ[i] = ft_setenv(node->tokens[1]);
	else
	{
		memmove(environ + envlen + 1, environ + envlen, 1 * sizeof(char *));
		environ[envlen] = ft_setenv(node->tokens[1]);
	}
	return (0);
}
