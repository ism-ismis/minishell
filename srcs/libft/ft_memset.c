/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:58:33 by yyamagum          #+#    #+#             */
/*   Updated: 2020/11/22 16:12:06 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_cpy;
	unsigned char	cc;

	b_cpy = (unsigned char *)b;
	cc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		b_cpy[i] = cc;
		i++;
	}
	return (b);
}
