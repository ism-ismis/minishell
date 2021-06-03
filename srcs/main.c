#include "minishell.h"
#include "parser.h"


int	launch_minishell(t_node *node)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;
	extern char **environ;

	pid = fork();
	if (pid == 0)
	{
		print_node(node);
		if (execve(node->cm_content, node->tokens, NULL) == -1)
			perror("launch_minishell");
	}
	else if (pid < 0)
		perror("launch_minishell");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char		*line;
	t_str_list	*splited_lines;
	t_str_list	*tmp;
	int		i;
	t_node	*node;

	write(1, "minishell > ", 12);
	while (minishell_get_next_line(0, &line) == 1)
	{
		splited_lines = shell_split(line);
		splited_lines = var_expansion(splited_lines);
		tmp = splited_lines;
		while (tmp)
		{
			printf("%s\n", tmp->s);
			if (!ft_strcmp(tmp->s, "exit"))
				exit(0);
			tmp = tmp->next;
		}
		free(line);
		node = semicolon_node_creator(&splited_lines);
		if (node->cm_kind == OTHER)
			launch_minishell(node);
		write(1, "minishell > ", 12);
	}
	return (0);
}
