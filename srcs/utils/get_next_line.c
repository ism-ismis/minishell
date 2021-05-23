/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:40:04 by yyamagum          #+#    #+#             */
/*   Updated: 2021/01/12 08:28:50 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add(char **line, char **stat, int len)
{
	char	*tmp;

	if (*stat)
		(*stat)[len] = '\0';
	tmp = ft_strjoin(*line, *stat);
	*line ? free(*line) : 0;
	*line = tmp;
}

int		get_next_buf(int fd, char **line, char **stat)
{
	char		*s;
	long		read_no;
	int			j;

	j = 0;
	while (*stat && (*stat)[j] != '\0' && (*stat)[j] != '\n')
		j++;
	if (*stat && (*stat)[j] == '\n')
	{
		add(line, stat, j);
		s = *stat;
		*stat = ft_strjoin(*stat + j + 1, NULL);
		free(s);
		return (*stat && *line ? -2 : -3);
	}
	add(line, stat, j);
	if (!(s = malloc(BUFFER_SIZE + 1)))
		return (-3);
	(read_no = read(fd, s, BUFFER_SIZE)) <= 0 ? free(s) : 0;
	if (read_no <= 0)
		return (read_no);
	*stat ? free(*stat) : 0;
	*stat = ft_strldup(s, read_no);
	free(s);
	return (*stat && *line ? 1 : -3);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	int			j;
	static char	*stat;

	if (line && !(*line = ft_strjoin(NULL, "")))
		return (-1);
	if (!line || BUFFER_SIZE <= 0 || INT_MAX - 1 <= BUFFER_SIZE)
		return (-1);
	i = 0;
	while (1)
	{
		if ((j = get_next_buf(fd, line, &stat)) == -2)
			break ;
		if (j <= 0)
		{
			if (stat)
				free(stat);
			stat = NULL;
			if (j == -3)
				return (-1);
			return (j);
		}
		i++;
	}
	return (1);
}
