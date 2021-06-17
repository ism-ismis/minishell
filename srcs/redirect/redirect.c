#include "redirect.h"

void print_list(t_list *list)
{
  t_list *ptr;

  ptr = list;
  while (ptr)
  {
    printf("%s\n", ptr->content);
    ptr = ptr->next;
  }
}

void	free_hd_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->content)
		{
			free((*list)->content);
			(*list)->content = NULL;
      *list = tmp;
		}
	}
  free(*list);
}

void start_here_document(t_node *node)
{
  char  *line;
  t_list *list;
  t_list *head;

  printf("start here_document!\n");
  list = NULL;
  head = list;
  while (1)
	{
    line = readline("> ");
    if (ft_strcmp(line, node->rd_content) == 0)
    {
      ft_safe_free(&line);
      break ;
    }
    if (!list)
      list = ft_lstnew(strdup(line));
    else
      ft_lstadd_back(&list, ft_lstnew(strdup(line)));
    ft_safe_free(&line);
	}
  print_list(list);
  free_hd_list(&list);
}

void set_redirect(t_node *node)
{
  int fd;

  if (node->rd_kind == OUT)
  {
    fd = open(node->rd_content, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    dup2(fd, 1);
    close(fd);
  }
  else if (node->rd_kind == IN)
  {
    fd = open(node->rd_content, O_RDONLY);
    dup2(fd, 0);
    close(fd);
  }
  else if (node->rd_kind == ADD)
  {
    fd = open(node->rd_content, O_WRONLY | O_CREAT | O_APPEND, 0666);
    dup2(fd, 1);
    close(fd);
  }
  else if (node->rd_kind == FD_OUT)
  {
    fd = open(node->rd_content, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    dup2(fd, node->rd_fd);
    close(fd);
  }
  else if (node->rd_kind == FD_IN)
  {
    fd = open(node->rd_content, O_RDONLY);
    dup2(fd, 0);
    close(fd);
  }
  else if (node->rd_kind == FD_ADD)
  {
    fd = open(node->rd_content, O_WRONLY | O_CREAT | O_APPEND, 0666);
    dup2(fd, node->rd_fd);
    close(fd);
  }
}
