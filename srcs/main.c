#include "minishell.h"
#include "utils.h"
#include "parser.h"
#include "exec.h"

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

void	free_list(t_str_list *splited_lines)
{
	t_str_list	*tmp;

	while (splited_lines)
	{
		tmp = splited_lines->next;
		if (splited_lines->s)
		{
			free(splited_lines->s);
			splited_lines->s = NULL;
		}
		free(splited_lines);
		splited_lines = NULL;
		splited_lines = tmp;
	}
}

int	exec_command(t_node *node)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;
	
	printf("Enter exec_command!\n");
	print_node(node);
	pid = fork();
	if (pid == 0)
	{
		if (node->rd_kind > 0)
			set_redirect(node);
		if (node->rd_kind == 4)
			start_here_document(node);
		else if (node->cm_kind == OTHER)
		{
			if (node->cm_content[0] != '/')
				node->cm_content = cm_relative_to_absolute(node);
			if (execve(node->cm_content, node->tokens, NULL) == -1)
				ft_putendl_fd("No such file or directory", 2);
		}
		else if (node->cm_kind > 0)
			launch_builtin(node);
		else
		{
			printf("????\n");
			return (1);
		}	
	}
	else if (pid < 0)
		perror("exec_command");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		printf("status:%d\n", WEXITSTATUS(status));
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (0);
}

void	inthandler(int sig)
{
	(void)sig;
	//printf("sig:%d\n", sig);
	exit(130);
}

int	command_launcher(void)
{
	pid_t		pid;
	pid_t		wpid;
	char		*line;
	t_str_list	*splited_lines;
	t_str_list	*tmp;
	t_node		*node;
	static int	status;
	//int			i=1;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, inthandler);//ctrl-C
		ft_putstr_fd("minishell > ", 1);
		if (minishell_get_next_line(0, &line) != 1)
			return (1);
		printf("line[%p]:%s\n", line, line);
		add_history(line);
		//HIST_ENTRY *x = history_get(i++);
		//printf("history:%s\n", x->line);
		splited_lines = shell_split(line);
		splited_lines = var_expansion(splited_lines);
		tmp = splited_lines;
		while (tmp)
		{
			printf("[%p][%p]%s\n", tmp, tmp->s, tmp->s);
			tmp = tmp->next;
		}
		tmp = splited_lines;
		node = semicolon_node_creator(&splited_lines);
		free(line);
		if (exec_command(node) == 1)
			return (0);
		if (node->cm_kind == EXIT) /* pipeありの場合はexitしない */
		{
			free_node(node);
			free(node);
			exit(0); /*  本当はg_exit_codeを子プロセスから引き継ぎたい*/
		}
		free_list(tmp);
		free_node(node);
		free(node);
	}
	else if (pid < 0)
		perror("launch command line");
	else
	{
		signal(SIGINT, SIG_IGN);//ctrl-C
		wpid = waitpid(pid, &status, WUNTRACED);
		printf("status:%d\n", WEXITSTATUS(status));
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	//printf("exit\n");
	//free_list(tmp);
	//free_node(node);
	//free(node);
	return (0);
}

int	main(void)
{
	int			n;

	signal(SIGQUIT, SIG_IGN);
	n = command_launcher();
	while (!n)
		n = command_launcher();
	// system("leaks minishell");
	return (0);
}
