/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:40:04 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 05:38:21 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add(char **line, char **stat, int len)
{
	char	*tmp;

	if (*stat)
		(*stat)[len] = '\0';
	tmp = ft_strjoin(*line, *stat);
	if (*line)
		free(*line);
	*line = tmp;
}

int	read_next_buf(int fd, char **line, char **stat)
{
	char	*s;
	long	read_no;

	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (-3);
	read_no = read(fd, s, BUFFER_SIZE);
	if (read_no <= 0)
		free(s);
	if (read_no <= 0)
		return (read_no);
	if (*stat)
		free(*stat);
	*stat = ft_strldup(s, read_no);
	free(s);
	if (*stat && *line)
		return (1);
	return (-3);
}

int	get_next_buf(int fd, char **line, char **stat)
{
	char	*s;
	int		j;

	j = 0;
	while (*stat && (*stat)[j] != '\0' && (*stat)[j] != '\n')
		j++;
	if (*stat && (*stat)[j] == '\n')
	{
		add(line, stat, j);
		s = *stat;
		*stat = ft_strjoin(*stat + j + 1, NULL);
		free(s);
		if (*stat && *line)
			return (-2);
		return (-3);
	}
	add(line, stat, j);
	return (read_next_buf(fd, line, stat));
}

int	get_next_line(int fd, char **line)
{
	int			j;
	static char	*stat;

	if (line)
		*line = ft_strjoin(NULL, "");
	if (!line || !*line || BUFFER_SIZE <= 0 || INT_MAX - 1 <= BUFFER_SIZE)
		return (-1);
	while (1)
	{
		j = get_next_buf(fd, line, &stat);
		if (j == -2)
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
	}
	return (1);
}
