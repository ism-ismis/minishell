#ifndef EXEC_H
# define EXEC_H

typedef struct s_node	t_node;

void set_redirect(t_node *node);
void start_here_document(t_node *node);
char    *cm_relative_to_absolute(t_node *node);

#endif
