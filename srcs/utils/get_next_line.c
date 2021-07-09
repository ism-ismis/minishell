/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:40:04 by yyamagum          #+#    #+#             */
/*   Updated: 2021/07/09 22:00:01 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../srcs/libft/libft.h"
// #include "minishell.h"

void	add(char **line, char **stat, int len)
{
	char	*tmp;

  	tmp = ft_strljoin(*line, *stat, len);
  	if (*line)
  		free(*line);
  	*line = tmp;
}

void	up_line(char **line, t_inter_list *ft_history)
{
	if (ft_history->pre)
		ft_history = ft_history->pre;
	if (ft_history)
	{
		//printf("%s\n", ft_history->line);
		//(*line)[ft_strlen(*line)-1] = 0;
		//*line = ft_strdup(*line);//need free
		write(1, "\rminishell > ", 13);
		write(1, ft_history->line, ft_strlen(ft_history->line));
		//write(1, " \x1b[1D", 5);
	}
	(void)line;
	(void)ft_history;
	return ;
}

int	read_next_buf(int fd, char **line, char **stat, t_inter_list *ft_history)
{
	char	*s;
	long	read_no;
	char	bs;

	bs = 8;
	s = malloc(2);
	if (!s)
		return (-3);
	*s = 0;
	while (!*s)
	{
		read_no = read(fd, s, 1);
		if (read_no < 0)
		{
			free(s);
			return (read_no);
		}
		if ((*s == 8 || *s == 127) && **line)
		{
			(*line)[ft_strlen(*line)-1] = 0;
			*line = ft_strdup(*line);//need free
			write(1, "\rminishell > ", 13);
			write(1, *line, ft_strlen(*line));
			write(1, " \x1b[1D", 5);
			//write(1, &bs, 1);
		}
		else if (s[0] == 0x1b)
		{
			read_no = read(fd, s, 1);
			//if (read_no < 0)
			if (*s != 0x5b)
				continue;
			read_no = read(fd, s, 1);
			//if (read_no < 0)
			if (*s == 0x41)
			{
				up_line(line, ft_history);
				return (1);
			}
			if (*s == 0x42)
			{
				printf("down\n");
				//down_line();
				return (1);
			}
		}
		else
			write(1, s, 1);
	}
	if (*stat)
		free(*stat);
	*stat = ft_strldup(s, read_no);//exception
	free(s);
	if (*stat && *line)
		return (1);
	return (-3);
}

int	is_closed_correctly(char **line)
{
	int	i;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] == '"')
		{
			while ((*line)[++i] && (*line)[i] != '"')
				;
			if (!(*line)[i])
				return (handle_odd_quote(DQUOTE));
		}
		else if ((*line)[i] == '\'')
		{
			while ((*line)[++i] && (*line)[i] != '\'')
				;
			if (!(*line)[i])
				return (handle_odd_quote(QUOTE));
		}
	}
	return (1);
}

int	get_next_buf(int fd, char **line, char **stat, t_inter_list *ft_history)
{
	char	*s;
	int		j;

	j = 0;
	while (*stat && (*stat)[j] != '\0' && (*stat)[j] != '\n')
	{
		if ((*stat)[j] == 0x1b && (*stat)[j + 1] == 0x5b
			&& ((*stat)[j + 2] == 0x41 || (*stat)[j + 2] == 0x42))
		{
			printf("arrow key\n");
			/*
			if ((*stat)[j + 2] == 0x41)
				up_line();
			else if ((*stat)[j + 2] == 0x42)
			   down_line(original_s);
			j += 2;
			*/
		}
		printf("%x ", (*stat)[j]);
		j++;
	}
	add(line, stat, j);
	if (*stat && (*stat)[j] == '\n' && is_closed_correctly(line))
	{
		s = *stat;
		*stat = ft_strjoin(*stat + j + 1, NULL);
		free(s);
		if (*stat && *line)
			return (-2);
		return (-3);
	}
	return (read_next_buf(fd, line, stat, ft_history));
}

int	minishell_get_next_line(int fd, char **line, t_inter_list *ft_history)
{
	int			j;
	static char	*stat;

	if (ft_history)
		while (ft_history->next)
			ft_history = ft_history->next;
	if (line)
		*line = ft_strdup("");
	if (!line || !*line)
		return (-1);
	while (1)
	{
		j = get_next_buf(fd, line, &stat, ft_history);
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
