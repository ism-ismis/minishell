#include "redirect.h"

void set_redirect(t_node *node)
{
  int fd;

  if (node->rd_kind == OUT)
  {
    fd = open(node->rd_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    dup2(fd, 1);
    close(fd);
  }
  else if (node->rd_kind == IN)
  {
    fd = open(node->rd_path, O_RDONLY);
    dup2(fd, 0);
    close(fd);
  }
  else if (node->rd_kind == ADD)
  {
    fd = open(node->rd_path, O_WRONLY | O_CREAT | O_APPEND, 0666);
    dup2(fd, 1);
    close(fd);
  }
  else if (node->rd_kind == FD_OUT)
  {
    fd = open(node->rd_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    dup2(fd, node->rd_fd);
    close(fd);
  }
  else if (node->rd_kind == FD_IN)
  {
    fd = open(node->rd_path, O_RDONLY);
    dup2(fd, 0);
    close(fd);
  }
  else if (node->rd_kind == FD_ADD)
  {
    fd = open(node->rd_path, O_WRONLY | O_CREAT | O_APPEND, 0666);
    dup2(fd, node->rd_fd);
    close(fd);
  }
}
