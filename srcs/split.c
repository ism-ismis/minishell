#include "minishell.h"

int	find_separator(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isspace(line[i]) && line[i] != ';'
		&& line[i] != '|' && line[i] != '>' && line[i] != '<')
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

int	count(char *line)
{
	int	i;
	int	len;

	i = 0;
	while (*line)
	{
		len = find_separator(line);
		if (len)
			i++;
		line += len;
		len = 1;
		if (*line && !ft_isspace(*line))
		{
			if (!ft_strncmp(line, ">>", 2))
				len = 2;
			i++;
		}
		if (*line)
			line += len;
	}
	return (i);
}

char	**shell_split(char *line)
{
	char	**splited_lines;
	int		i;
	int		len;

	splited_lines = (char **)malloc((count(line) + 1) * sizeof(char *));
	i = 0;
	while (*line)
	{
		len = find_separator(line);
		if (len)
			splited_lines[i++] = ft_strldup(line, len);
		line += len;
		len = 1;
		if (*line && !ft_isspace(*line))
		{
			if (!ft_strncmp(line, ">>", 2))
				len++;
			splited_lines[i++] = ft_strldup(line, len);
		}
		if (*line)
			line += len;
	}
	splited_lines[i] = NULL;
	return (splited_lines);
}
