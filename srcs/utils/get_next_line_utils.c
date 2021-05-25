/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_net_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:54:08 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 20:58:20 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "minishell.h"

int	handle_odd_quote(char **line, int i, int quote_type)
{
	if (quote_type == QUOTE)
		write(1, "quote> ", 7);
	else if (quote_type == DQUOTE)
		write(1, "dquote> ", 8);
	return (0);
}

static char	*insert(char *ss, char const *s1, char const *s2, int len)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	if (s1)
		while (s1[i])
			ss[index++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i] && i < len)
			ss[index++] = s2[i++];
	ss[index] = '\0';
	return (ss);
}

char	*stradd(char *s1, char *s2)
{
	int		len;
	char	*ss;

	while (*s1)
		s1++;
	len = 0;
	if (s2)
		while (s2[len])
			len++;
	ss = (char *)malloc((len + 1) * sizeof(char));
	if (!ss)
		return (NULL);
	ss = insert(ss, s1, s2, ft_strlen(s2));
	return (s1);
}

char	*ft_strljoin(char const *s1, char const *s2, int len)
{
	char	*ss;

	len += ft_strlen(s1);
	ss = (char *)malloc((len + 1) * sizeof(char));
	if (!ss)
		return (NULL);
	ss = insert(ss, s1, s2, ft_strlen(s2));
	return (ss);
}

char	*ft_strldup(const char *src, long len)
{
	char	*cpy;
	long	i;

	if (!src)
		return (NULL);
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
