#include "ft_history.h"
#include "minishell.h"

void	print_history(void)
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

void	ft_print_history(t_inter_list *ft_history)
{
	int	i;

	printf("~~~~ft_history~~~~\n");
	i = 1;
	if (ft_history)
		while (ft_history->pre)
			ft_history = ft_history->pre;
	while (ft_history)
	{
		if (ft_history->line)
			printf("  %d  %s\n", i, ft_history->line);
		ft_history = ft_history->next;
		i++;
	}
}

t_inter_list	*init_history(char *line)
{
	t_inter_list	*ft_history;

	ft_history = malloc(sizeof(t_inter_list));
	if (!ft_history)
		return (NULL);
	ft_history->pre = NULL;
	ft_history->line = ft_strdup(line);
	ft_history->next = malloc(sizeof(t_inter_list));
	if (!ft_history->next)
		return (NULL);
	ft_history->next->pre = ft_history;
	ft_history = ft_history->next;
	ft_history->line = NULL;
	ft_history->next = NULL;
	return (ft_history);
}

t_inter_list	*ft_add_history(t_inter_list *ft_history, char *line)
{
	t_inter_list	*start;
	t_inter_list	*next;

	start = ft_history;
	if (!ft_history)
		return (init_history(line));
	while (ft_history->next)
		ft_history = ft_history->next;
	ft_history->line = ft_strdup(line);
	next = malloc(sizeof(t_inter_list));
	if (!next)
		return (NULL);
	ft_history->next = next;
	next->pre = ft_history;
	next->line = NULL;
	next->next = NULL;
	return (start);
}

int	ft_inter_listlen(t_inter_list *ft_history)
{
	int	i;

	i = 0;
	while (ft_history)
	{
		ft_history = ft_history->next;
		i++;
	}
	return (i);
}
