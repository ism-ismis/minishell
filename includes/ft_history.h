#ifndef FT_HISTORY_H
# define FT_HISTORY_H
#include <stdlib.h>

typedef	struct s_inter_list
{
	struct s_inter_list	*pre;
	char	*line;
	struct s_inter_list	*next;
}	t_inter_list;

t_inter_list	*ft_add_history(t_inter_list *ft_history, char *line);
int	ft_inter_listlen(t_inter_list *ft_history);
void	print_history(void);
void	ft_print_history(t_inter_list *ft_history);

#endif
