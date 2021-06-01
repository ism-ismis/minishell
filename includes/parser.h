#ifndef PARSER_H
# define PARSER_H

#include "minishell.h"

typedef int t_bool;

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

typedef struct s_token
{
	char			*str;
	struct s_token	*next;
}			t_token;

typedef struct s_node
{
	t_node_kind		nd_kind;
	t_command_kind	cm_kind;
	struct s_node	*lhs;
	struct s_node	*rhs;
	t_token			*tokens;
	char			*cm_content;
}		t_node;

t_node	*semicolon_node_creator(t_str_list *token_list);

#endif
