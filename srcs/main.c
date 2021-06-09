#include "minishell.h"
#include "parser.h"


int	launch_builtin(t_node *node)
{
	if (node->cm_kind == ECHO)
		ft_echo(node);
	else if (node->cm_kind == PWD)
		ft_pwd(node);
	else if (node->cm_kind == CD)
		ft_cd(node);
	else if (node->cm_kind == EXPORT)
		ft_export(node);
	else if (node->cm_kind == UNSET)
		ft_unset(node);
	else if (node->cm_kind == ENV)
		ft_env(node);
	else if (node->cm_kind == EXIT)
		ft_exit(node);
	return (1);
}

int	launch_command_path(t_node *node)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;
	int 	fd;
	extern char **environ;

	printf("Enter launch_command_path!\n");
	pid = fork();
	if (pid == 0)
	{
		print_node(node);
		if (node->rd_kind == OUT)
		{
			fd = open(node->redirect_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
			dup2(fd, 1);
			close(fd);
		}
		else if (node->rd_kind == IN)
		{
			fd = open(node->redirect_path, O_RDONLY);
			dup2(fd, 0);
			close(fd);
		}
		else if (node->rd_kind == ADD)
		{
			fd = open(node->redirect_path, O_WRONLY | O_CREAT | O_APPEND, 0666);
			dup2(fd, 1);
			close(fd);
		}
		if (execve(node->cm_content, node->tokens, NULL) == -1)
			ft_printf("No such file or directory\n");
			// perror("launch_minishell");
	}
	else if (pid < 0)
		perror("launch_command_path");
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

	ft_printf("minishell > ");
	//write(1, "minishell > ", 12);
	//fflush(stdout);
	while (minishell_get_next_line(0, &line) == 1)
	{
		splited_lines = shell_split(line);
		splited_lines = var_expansion(splited_lines);
		tmp = splited_lines;
		while (tmp)
		{
			ft_printf("%s\n", tmp->s);
			if (!ft_strcmp(tmp->s, "exit"))
				exit(0);
			tmp = tmp->next;
		}
		free(line);
		node = semicolon_node_creator(&splited_lines);
		if (node->cm_kind == OTHER)
			launch_command_path(node);
		else
			launch_builtin(node);
		ft_printf("minishell > ");
		//write(1, "minishell > ", 12);
	}
	return (0);
}
