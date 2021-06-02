#include "minishell.h"

int	is_separator(char c)
{
	return (ft_isspace(c) || c == ';' || c == '|' || c == '>' || c == '<');
}

int	find_separator(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isspace(line[i]) && !is_separator(line[i]))
	{
		if (line[i] == '"')
		{
			while (line[++i] != '"')
				;
			i++;
		}
		else if (line[i] == '\'')
		{
			while (line[++i] != '\'')
				;
			i++;
		}
		else
			i++;
	}
	return (i);
}

t_str_list	*get_next_word(char **line, t_str_list *splited_lines)
{
	int	i;

	i = find_separator(*line);
	if (i)
	{
		splited_lines->next = malloc(sizeof(t_str_list));
		splited_lines = splited_lines->next;
		splited_lines->s = ft_strldup(*line, i);
	}
	*line += i;
	i = 1;
	if (*line && **line && !ft_isspace(**line))
	{
		if (!ft_strncmp(*line, ">>", 2))
			i++;
		splited_lines->next = malloc(sizeof(t_str_list));
		splited_lines = splited_lines->next;
		splited_lines->s = ft_strldup(*line, i);
	}
	if (**line)
		*line += i;
	return (splited_lines);
}

t_str_list	*shell_split(char *line)
{
	t_str_list	*splited_lines;
	t_str_list	*start;
	int			len;

	splited_lines = malloc(sizeof(t_str_list));
	start = splited_lines;
	while (*line)
		splited_lines = get_next_word(&line, splited_lines);
	splited_lines->next = NULL;
	splited_lines = start->next;
	free(start);
	return (splited_lines);
}
