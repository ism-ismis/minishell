/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:19:34 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 03:26:07 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	void	*cpy;
	size_t	i;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	cpy = s;
	i = 0;
	while (i < count)
	{
		ft_bzero(s, size);
		s += size;
		i++;
	}
	return (cpy);
}
