#include "minishell.h"

int	is_separator(char c)
{
	return (ft_isspace(c) || c == ';' || c == '|' || c == '<' || c == '>');
}

int	search_behind_redirect_option(char *s, int i)
{
	int	j;

	if (is_separator(s[i]) && s[i] != '>')
		return (0);
	j = 0;
	if (s[i] == '>')
		j++;
	if (s[i + j] == '&')
	{
		j++;
		while (ft_isdigit(s[i + j]))
			j++;
		if (is_separator(s[i + j]))
			return(j);
		if (s[i] == '>')
			return (2);
		else
			return (1);
	}
	return (j);
}

int	search_front_redirect_option(char *s, int i)
{
	if (i == 1)
		if (ft_isdigit(s[0]) || s[0] == '&')
			return (-1);
	if (i >= 1 && s[i - 1] == '&')
		return (-1);
	return (0);
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
	int	j;

	i = find_separator(*line);
	j = 0;
	if ((*line)[i] == '>')
		j = search_front_redirect_option(*line, i);
	if (i + j)
	{
		splited_lines->next = malloc(sizeof(t_str_list));
		splited_lines = splited_lines->next;
		splited_lines->s = ft_strldup(*line, i + j);
	}
	*line += i;
	i = 0;
	if (**line == '>')
		i += search_behind_redirect_option(*line, 1);
	*line += j;
	if (*line && **line && !ft_isspace(**line))
	{
		splited_lines->next = malloc(sizeof(t_str_list));
		splited_lines = splited_lines->next;
		splited_lines->s = ft_strldup(*line, i + 1 - j);
	}
	*line += i + 1 - j;
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
