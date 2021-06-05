#include "parser.h"


void	print_tokens(char **tokens)
{
	int	i;
	char **ptr;

	i = 0;
	ptr = tokens;
	printf("node_tokens:\n");
	while(ptr[i])
	{
		printf("[%d]:%s ", i, ptr[i]);
		i++;
	}
	printf("\n");
}

void	print_node_command(t_node *node)
{
	if (node->nd_kind >= 1)
	{
		if (node->cm_kind == 1)
			printf("nd_command:echo\n");
		else if (node->cm_kind == 2)
			printf("nd_command:cd\n");
		else if (node->cm_kind == 3)
			printf("nd_command:pwd\n");
		else if (node->cm_kind == 4)
			printf("nd_command:export\n");
		else if (node->cm_kind == 5)
			printf("nd_command:unset\n");
		else if (node->cm_kind == 6)
			printf("nd_command:env\n");
		else if (node->cm_kind == 7)
			printf("nd_command:exit\n");
		else if (node->cm_kind == 8)
			printf("nd_command:expansion\n");
		else if (node->cm_kind == 9)
			printf("nd_command:%s\n", node->cm_content);
		else
			printf("nd_command:???\n");
	}
	if (node->tokens)
		print_tokens(node->tokens);
	else
		printf("node_tokens: NULL\n");
	if (node->redirect_info)
		printf("redirect_info:%s\n", node->redirect_info);
}

void	print_node(t_node *node)
{
	printf("---node info---\n");
	printf("node_kind:%d\n", node->nd_kind);
	if (node->nd_kind >= 1 && node->nd_kind <= 8)
		print_node_command(node);
	else
	{
		if (node->lhs)
		{
			printf("node_lhs:%d\n", node->lhs->nd_kind);
			if (node->lhs->nd_kind == 1)
				print_node_command(node->lhs);
		}
		else
			printf("node_lhs:NULL\n");
		if (node->rhs)
		{
			printf("node_rhs:%d\n", node->rhs->nd_kind);
			if (node->rhs->nd_kind == 1)
				print_node_command(node->rhs);
		}
		else
			printf("node_rhs:NULL\n");
	}
	printf("---------------\n");
}

t_node	*new_node(t_node_kind nd_kind, t_node *lhs, t_node *rhs)
{
	t_node *node;

	printf("let's make a new node!\n");
	node = ft_calloc(1, sizeof(t_node));
	node->nd_kind = nd_kind;
	node->lhs = lhs;
	node->rhs = rhs;
	return (node);
}

int		define_token_size(t_str_list *list)
{
	int	len;
	t_str_list	*ptr;

	ptr = list;
	if (!ptr)
		return (0);
	len = 1;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		len++;
	}
	return (len);
}

char	*set_args_option(char *str)
{
	char	*option;
	int		len;

	printf("set_args_option str:%s ", str);
	len = ft_strlen(str);
	option = ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(option, str, len + 1);
	return (option);
}

char	*set_args_content(t_str_list **list)
{
	char	*line;
	t_str_list	*head;
	int		len;
	int		i;
	int		j;

	printf("start set_args_content!\n");
	head = *list;
	len = 0;
	while (*list && *(*list)->s != ';' && *(*list)->s != '|' && *(*list)->s != '<' && *(*list)->s != '<')
	{
		(*list)->s = remove_quotations((*list)->s);
		len += ft_strlen((*list)->s) + 1;
		*list = (*list)->next;
	}
	line = ft_calloc(len, sizeof(char));
	i = 0;
	*list = head;
	while (*list && *(*list)->s != ';' && *(*list)->s != '|' && *(*list)->s != '<' && *(*list)->s != '<')
	{
		j = 0;
		while ((*list)->s[j])
			line[i++] = (*list)->s[j++];
		line[i++] = ' ';
		*list = (*list)->next;
	}
	line[--i] = 0;
	return (line);
}


char	**define_args(t_str_list **list, t_node *node)
{
	char	**args;
	int		i;
	t_str_list	*head;

	printf("enter define_args!\n");
	head = *list;
	i = 0;
	while (*list && *(*list)->s == '-' && *((*list)->next->s) != 0)
	{
		i++;
		*list = (*list)->next;
	}
	args = ft_calloc(i + 3, sizeof(char **));
	printf("size of arg: %d\n", i + 2);
	args[0] = node->cm_content;
	*list = head;
	i = 1;
	(*list)->s = remove_quotations((*list)->s);
	while (*list && *(*list)->s == '-' && *((*list)->next->s) != 0)
	{
		args[i] = set_args_option((*list)->s);
		*list = (*list)->next;
		(*list)->s = remove_quotations((*list)->s);
		i++;
	}
	args[i] = set_args_content(list);
	args[++i] = NULL;
	printf("end define_args!\n");
	return (args);
}

t_node *command_node_creator(t_str_list **token_list)
{
	t_node *node;

	printf("enter command_node_creator!\n");
	node = new_node(ND_COMMAND, NULL, NULL);
	if (!(ft_strncmp((*token_list)->s, "echo", 5)))
		node->cm_kind = ECHO;
	else if (!(ft_strncmp((*token_list)->s, "cd", 3)))
		node->cm_kind = CD;
	else if (!(ft_strncmp((*token_list)->s, "pwd", 4)))
		node->cm_kind = PWD;
	else if (!(ft_strncmp((*token_list)->s, "export", 7)))
		node->cm_kind = EXPORT;
	else if (!(ft_strncmp((*token_list)->s, "unset", 6)))
		node->cm_kind = UNSET;
	else if (!(ft_strncmp((*token_list)->s, "env", 4)))
		node->cm_kind = ENV;
	else if (!(ft_strncmp((*token_list)->s, "exit", 5)))
		node->cm_kind = EXIT;
	else if (!(ft_strncmp((*token_list)->s, "$", 1)))
		node->cm_kind = EXPANSION;
	else
		node->cm_kind = OTHER;
	node->cm_content = (*token_list)->s;
	(*token_list) = (*token_list)->next;
	node->tokens = define_args(token_list, node);
	if (*token_list)
	{
		(*token_list)->s = remove_quotations((*token_list)->s);
		node->redirect_info = (*token_list)->s;
	}
	print_node(node);
	printf("end command_node_creator!\n");
	return (node);
}

t_node *pipe_node_creator(t_str_list **token_list)
{
	t_node	*node;

	printf("enter pipe_node_creator!\n");
	if (*token_list == 0)
		return (NULL);
	if (*((*token_list)->s) == '|')
	{
		printf("syntax error near unexpected token `|'\n");
		return (NULL);
	}
	node = command_node_creator(token_list);
	while (1)
	{
		if (*token_list && *((*token_list)->s) == '|')
		{
			*token_list = (*token_list)->next;
			node = new_node(ND_PIPE, node, command_node_creator(token_list));
			print_node(node);
		}
		else
			return (node);
	}
}

t_node	*semicolon_node_creator(t_str_list **token_list)
{
	t_node	*node;

	printf("enter semicolon_node_creator!\n");
	if (*token_list == 0)
		return (NULL);
	if (*((*token_list)->s) == ';')
	{
		printf("syntax error near unexpected token `;'\n");
		return (NULL);
	}
	node = pipe_node_creator(token_list);
	while (1)
	{
		if (*token_list && *((*token_list)->s) == ';')
		{
			*token_list = (*token_list)->next;
			node = new_node(ND_SEMICOLON, node, pipe_node_creator(token_list));
			print_node(node);
		}
		else
			return (node);
	}
}
