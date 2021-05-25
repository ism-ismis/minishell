/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 05:34:08 by yyamagum          #+#    #+#             */
/*   Updated: 2020/11/22 16:22:26 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	if (dst == src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (d <= s)
	{
		i = -1;
		while (++i < len)
			d[i] = s[i];
	}
	else
	{
		i = len;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (dst);
}
