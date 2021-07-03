#include "minishell.h"
#include "parser.h"

char	*get_pre_dir(char *relative_path, int i)
{
	int	j;

	j = 0;
	while (j <= i && relative_path[i - j] != '/')
		j++;
	return (ft_strldup(relative_path + i - j + 1, j));
}

char	*remove_last_dir(char *absolute_path)
{
	int	i;

	i = ft_strlen(absolute_path) - 1;
	while (i >= 0 && absolute_path[i] != '/')
		i--;
	return (ft_strldup(absolute_path, i));
}

char	*relative_to_absolute(char *relative_path, char *cwd)
{
	char	*dir;
	int		i;
	char	*absolute_path;
	char	*tmp;

	if (*relative_path == '/')
		absolute_path = ft_strdup("/");
	else
		absolute_path = ft_strdup(cwd);
	i = ft_strlen(relative_path) - 1;
	while (i >= 0)
	{
		dir = get_pre_dir(relative_path, i);
		if (ft_strncmp(dir, ".", 2) && ft_strncmp(dir, "..", 3))
		{
			tmp = absolute_path;
			absolute_path = ft_strjoin(absolute_path, "/");
			free(tmp);
			tmp = absolute_path;
			absolute_path = ft_strjoin(absolute_path, dir);
			free(tmp);
		}
		else if (!ft_strncmp(dir, "..", 3))
		{
			tmp = absolute_path;
			absolute_path = remove_last_dir(absolute_path);
			free(tmp);
		}
		i -= ft_strlen(dir);
		if (i >= 0 && relative_path[i] == '/')
			i--;
		free(dir);
	}
	return (absolute_path);
}

int	ft_cd(t_node *node)
{
	char	*cwd;
	char	*path;

	cwd = ft_getcwd();
	path = relative_to_absolute(node->tokens[1], cwd);
	chdir(path);
	free(cwd);
	free(path);
	return (0);
}
