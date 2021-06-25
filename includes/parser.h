#ifndef PARSER_H
# define PARSER_H

typedef struct s_str_list	t_str_list;

typedef enum e_node_kind {
	ND_EOF = -1,
	ND_SEMICOLON = ';',
	ND_PIPE = '|',
	ND_COMMAND = 1
}		t_node_kind;

typedef enum	e_command_kind
{
	ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	EXPANSION,
	OTHER
}		t_command_kind;

typedef enum	e_redirect_kind
{
	OUT = 1, /* > */
	IN, /* < */
	ADD, /* >> */
	HD, /* << */
	FD_OUT, /* 2> */
	FD_IN, /* 2< */
	FD_ADD, /*2>> */
	// STOE_OUT, /* &> */
	// STOE_ADD, /* &>> */
}		t_redirect_kind;

typedef struct s_token
{
	char			*str;
	struct s_token	*next;
}			t_token;

typedef struct s_node
{
	t_node_kind		nd_kind;
	t_command_kind	cm_kind;
	char			*cm_content;
	struct s_node	*lhs;
	struct s_node	*rhs;
	char			**tokens;
	t_redirect_kind	rd_kind;
	char			*rd_content;
	int				rd_fd;
}		t_node;

t_node	*semicolon_node_creator(t_str_list **token_list);
void	ft_safe_free(char **str);

void	print_node(t_node *node);

#endif
