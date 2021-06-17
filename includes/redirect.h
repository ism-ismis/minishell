#ifndef REDIRECT_H
# define REDIRECT_H

#include "minishell.h"
#include "parser.h"

void set_redirect(t_node *node);
void start_here_document(t_node *node);

#endif
