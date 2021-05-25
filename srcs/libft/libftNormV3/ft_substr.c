/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:24:02 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 03:29:22 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i++])
		;
	if (i <= start)
		len = 0;
	else if (--i < start + len + 1)
		len = i - start;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (!s[start + i])
			break ;
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
