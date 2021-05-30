#include "parser.h"

void	print_tokens(t_token *tokens)
{
	t_token *ptr;

	ptr = tokens;
	printf("node_tokens: ");
	while (ptr)
	{
		printf("%s ", ptr->str);
		ptr = ptr->next;
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
			// printf("rhs!!!\n");
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

	printf("let's make new node!\n");
	node = ft_calloc(1, sizeof(t_node));
	node->nd_kind = nd_kind;
	node->lhs = lhs;
	node->rhs = rhs;
	return (node);
}

void	define_tokens(char ***token_list, t_node *node)
{
	t_token *new_token;
	t_token *last;

	printf("enter define_tokens! first token:%s\n", **token_list);
	while (**token_list && ***token_list != ';' && ***token_list != '|')
	{
		new_token = ft_calloc(1, sizeof(t_token));
		new_token->str = **token_list;
		new_token->next = NULL;
		if (node->tokens == NULL)
			node->tokens = new_token;
		else
		{
			last = node->tokens;
			while (last->next)
				last = last->next;
			last->next = new_token;
		}
		(*token_list)++;
	}
	printf("end define_tokens!\n");
}

t_node *command_node_creator(char ***token_list)
{
	t_node *node;

	printf("enter command_node_creator!\n");
	node = new_node(ND_COMMAND, NULL, NULL);
	if (!(ft_strncmp(**token_list, "echo", 5)))
		node->cm_kind = ECHO;
	else if (!(ft_strncmp(**token_list, "cd", 3)))
		node->cm_kind = CD;
	else if (!(ft_strncmp(**token_list, "pwd", 4)))
		node->cm_kind = PWD;
	else if (!(ft_strncmp(**token_list, "export", 7)))
		node->cm_kind = EXPORT;
	else if (!(ft_strncmp(**token_list, "unset", 6)))
		node->cm_kind = UNSET;
	else if (!(ft_strncmp(**token_list, "env", 4)))
		node->cm_kind = ENV;
	else if (!(ft_strncmp(**token_list, "exit", 5)))
		node->cm_kind = EXIT;
	else if (!(ft_strncmp(**token_list, "$", 1)))
		node->cm_kind = EXPANSION;
	else
	{
		node->cm_kind = OTHER;
		node->cm_content = **token_list;
	}
	(*token_list)++;
	define_tokens(token_list, node);
	print_node(node);
	printf("end command_node_creator!\n");
	return (node);
}

t_node *pipe_node_creator(char ***token_list)
{
	t_node	*node;

	printf("enter pipe_node_creator!\n");
	if (**token_list == 0)
		return (NULL);
	if (***token_list == '|')
	{
		printf("syntax error near unexpected token `|'\n");
		return (NULL);
	}
	node = command_node_creator(token_list);
	while (1)
	{
		if (**token_list && ***token_list == '|')
		{
			(*token_list)++;
			// node = new_node(ND_PIPE, node, pipe_node_creator(token_list));
			node = new_node(ND_PIPE, node, command_node_creator(token_list));
			print_node(node);
		}
		else
			return (node);
	}
}

t_node	*semicolon_node_creator(char ***token_list)
{
	t_node	*node;

	printf("enter semicolon_node_creator!\n");
	if (**token_list == 0)
		return (NULL);
	if (***token_list == ';')
	{
		printf("syntax error near unexpected token `;'\n");
		return (NULL);
	}
	node = pipe_node_creator(token_list);
	// printf("first token:%s\n", **token_list);
	while (1)
	{
		if (**token_list && ***token_list == ';')
		{
			(*token_list)++;
			// node = new_node(ND_SEMICOLON, node, semicolon_node_creator(token_list));
			node = new_node(ND_SEMICOLON, node, pipe_node_creator(token_list));
			print_node(node);
		}
		else
			return (node);
	}
}

