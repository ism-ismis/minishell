/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:05:01 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 03:42:54 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_join(char const *s1, char const *s2)
{
	int	i;
	int	j;

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
	int	index;
	int	i;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	int		len;

	len = ft_len_join(s1, s2);
	ss = (char *)malloc((len + 1) * sizeof(char));
	if (!ss)
		return (NULL);
	ss = insert(ss, s1, s2);
	return (ss);
}
