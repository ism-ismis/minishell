/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_net_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:54:08 by yyamagum          #+#    #+#             */
/*   Updated: 2021/01/10 22:43:24 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_len_join(char const *s1, char const *s2)
{
	int i;
	int j;

	i = 0;
	if (s1)
		while (s1[i])
			i++;
	j = 0;
	if (s2)
		while (s2[j])
			j++;
	return (i + j);
}

static char	*insert(char *ss, char const *s1, char const *s2)
{
	int index;
	int i;

	index = 0;
	i = 0;
	if (s1)
		while (s1[i])
			ss[index++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i])
			ss[index++] = s2[i++];
	ss[index] = '\0';
	return (ss);
}

char		*stradd(char *s1, char *s2)
{
	int		len;
	char	*ss;

	while (*s1)
		s1++;
	len = 0;
	if (s2)
		while (s2[len])
			len++;
	if (!(ss = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ss = insert(ss, s1, s2);
	return (s1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	int		len;

	len = 10;
	len = ft_len_join(s1, s2);
	if (!(ss = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ss = insert(ss, s1, s2);
	return (ss);
}

char		*ft_strldup(const char *src, long len)
{
	char	*cpy;
	long	i;

	if (!src)
		return (NULL);
	if (!(cpy = (char *)malloc((len + 1) * sizeof(char))))
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
