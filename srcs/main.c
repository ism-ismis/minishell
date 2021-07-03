#include "minishell.h"
#include "utils.h"
#include "parser.h"
#include "exec.h"

int	launch_builtin(t_node *node)
{
	if (node->cm_kind == ECHO)
		return (ft_echo(node));
	else if (node->cm_kind == PWD)
		return (ft_pwd(node));
	else if (node->cm_kind == CD)
		return (ft_cd(node));
	else if (node->cm_kind == EXPORT)
		return (ft_export(node));
	else if (node->cm_kind == UNSET)
		return (ft_unset(node));
	else if (node->cm_kind == ENV)
		return (ft_env(node));
	else if (node->cm_kind == EXIT)
		return (ft_exit(node));
	return (-1);
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

int	exec_command(t_node *node, int *status)
{
	pid_t	pid;
	pid_t	wpid;
	//int		status;
	
	printf("Enter exec_command!\n");
	print_node(node);
	pid = fork();
	if (pid == 0)
	{
		if (node->cm_content[0] != '/')
			node->cm_content = cm_relative_to_absolute(node);
		if (execve(node->cm_content, node->tokens, NULL) == -1)
			ft_putendl_fd("No such file or directory", 2);
		exit(0);
	}
	else if (pid < 0)
		perror("exec_command");//forbidden func?
	else
	{
		wpid = waitpid(pid, status, WUNTRACED);
		while (!WIFEXITED(*status) && !WIFSIGNALED(*status))
			wpid = waitpid(pid, status, WUNTRACED);
	}
	return (0);
}

void	inthandler(int sig)
{
	(void)sig;
	//printf("sig:%d\n", sig);
	//exit (130);
	printf("\n");
	new_prompt();
}

void	ft_print_history(void)
{
	int	i;
	HIST_ENTRY *x;

	printf("~~~~history~~~~\n");
	i = 1;
	x = history_get(i);
	while (x)
	{
		printf("history[%d]:%s\n", i, x->line);
		x = history_get(i);
		i++;
	}
	return ;
}

t_node	*get_tree(int status)
{
	char		*line;
	t_str_list	*splited_lines;
	t_str_list	*tmp;
	t_node		*node;
	int			n;

	ft_putstr_fd("minishell > ", 1);
	n = minishell_get_next_line(0, &line);
	if (n != 1)
	{
		free(line);
		printf("exit\n");
		exit(0);//n == 0 -> ctrl-D
	}
	printf("add %s\n", line);
	add_history(line);
	ft_print_history();
	splited_lines = shell_split(line);
	splited_lines = var_expansion(splited_lines, &status);
	tmp = splited_lines;
	while (tmp)
	{
		printf("[%p][%p]%s\n", tmp, tmp->s, tmp->s);
		tmp = tmp->next;
	}
	tmp = splited_lines;
	node = semicolon_node_creator(&splited_lines);
	free(line);
	free_list(tmp);
	return (node);
}

int	new_prompt(void)
{
	t_node		*node;
	static int	status;

	node = get_tree(status);
	if (node->rd_kind == 4)
		start_here_document(node);
	else if (node->rd_kind > 0)
		set_redirect(node);
	if (node->cm_kind == EXIT) /* pipeありの場合はexitしない */
	{
		free_node(node);
		free(node);
		exit(0); /*  本当はg_exit_codeを子プロセスから引き継ぎたい*/
	}
	else if (node->cm_kind == OTHER && exec_command(node, &status) == 1)//save exit status
		printf("exec_command failed.");
	else if (node->cm_kind > 0)
		status = launch_builtin(node);
	else
	{
		printf("????\n");
		status = 1;
	}
	free_node(node);
	free(node);
	return (0);
}

int	main(void)
{
	int			n;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, inthandler);//ctrl-C
	n = new_prompt();
	while (!n)
		n = new_prompt();
	// system("leaks minishell");
	return (0);
}
