#include "minishell.h"
#include "parser.h"


char    *cm_relative_to_absolute(t_node *node)
{
	char	*cwd;
	char	*relative_path;
	char	*absolute_path;
	char	*tmp;

	printf("Enter cm_relative_to_absoulte\n");
	cwd = ft_getcwd();
	relative_path = node->cm_content;
	absolute_path = cwd;
	if (!(ft_strncmp(relative_path, "./", 2)))
	{
		relative_path += 2;
		relative_path = ft_strdup(relative_path);	
	}
	tmp = absolute_path;
	absolute_path = ft_strjoin(absolute_path, "/");
	free(tmp);
	tmp = absolute_path;
	absolute_path = ft_strjoin(absolute_path, relative_path);
	free(tmp);
	printf("pwd_path:%s\n", absolute_path);
	return (absolute_path);
}
