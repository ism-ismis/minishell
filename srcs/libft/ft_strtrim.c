/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:29:42 by yyamagum          #+#    #+#             */
/*   Updated: 2021/06/02 14:13:17 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set) == 1)
		start++;
	end = ft_strlen((char *)s1);
	while (end > 0 && is_in_set(s1[--end], set) == 1)
		;
	if (start > end)
		start = end + 1;
	cpy = (char *)malloc((end - start + 2) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (start <= end)
		cpy[i++] = s1[start++];
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strltrim(char const *s1, size_t l)
{
	char	*cpy;
	char	*s2;

	if (!s1)
		return (NULL);
	s2 = malloc((l + 2) * sizeof(char));
	ft_strlcpy(s2, s1, l + 1);
	cpy = ft_strjoin(s2, s1 + l + 1);
	return (cpy);
}
