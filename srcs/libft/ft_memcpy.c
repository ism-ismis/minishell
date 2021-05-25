/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 05:12:26 by yyamagum          #+#    #+#             */
/*   Updated: 2020/11/23 09:14:10 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = -1;
	if (dst <= src)
		while (++i < n)
			*d++ = s[i];
	else
	{
		i = n;
		d += i - 1;
		while (i-- > 0)
			*d-- = s[i];
	}
	return (dst);
}
