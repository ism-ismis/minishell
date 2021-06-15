#include "minishell.h"

int	is_separator(char c)
{
	return (ft_isspace(c) || c == ';' || c == '|' || c == '<' || c == '>');
}

int	search_behind_redirect_option(char *s, int i)
{
	int	j;
	char	rd_kind;

	if (*s != '>' && *s != '<')
		return (0);
	rd_kind = *s;
	if (is_separator(s[i]) && s[i] != rd_kind)
		return (0);
	j = 0;
	if (s[i] == rd_kind)
		j++;
	if (s[i + j] == '&')
	{
		j++;
		while (ft_isdigit(s[i + j]))
			j++;
		if (is_separator(s[i + j]))
			return (j);
		if (s[i] == rd_kind)
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
