/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 05:40:05 by yyamagum          #+#    #+#             */
/*   Updated: 2020/11/23 00:41:02 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cpy;
	size_t			i;
	unsigned char	cc;

	if (n == 0)
		return (NULL);
	s_cpy = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_cpy[i] == cc)
			return ((void *)&(s_cpy[i]));
		i++;
	}
	return (NULL);
}
