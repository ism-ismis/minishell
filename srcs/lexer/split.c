#include "minishell.h"
#include "lexer.h"

t_str_list	*get_next_word(char **line, t_str_list *splited_lines)
{
	int	i;
	int	j;

	i = find_separator(*line);
	j = 0;
	if ((*line)[i] == '>' || (*line)[i] == '<')
		j = search_front_redirect_option(*line, i);
	if (i + j)
	{
		splited_lines->next = malloc(sizeof(t_str_list));
		splited_lines = splited_lines->next;
		splited_lines->s = ft_strldup(*line, i + j);
	}
	*line += i;
	i = search_behind_redirect_option(*line, 1);
	*line += j;
	if (*line && **line && !ft_isspace(**line))
	{
		splited_lines->next = malloc(sizeof(t_str_list));
		splited_lines = splited_lines->next;
		splited_lines->s = ft_strldup(*line, i + 1 - j);
	}
	*line += i - j;
	if (**line)
		*line += 1;
	return (splited_lines);
}

t_str_list	*shell_split(char *line)
{
	t_str_list	*splited_lines;
	t_str_list	*start;

	splited_lines = malloc(sizeof(t_str_list));
	start = splited_lines;
	while (line && *line)
		splited_lines = get_next_word(&line, splited_lines);
	splited_lines->next = NULL;
	splited_lines = start->next;
	free(start);
	return (splited_lines);
}
