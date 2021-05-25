/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:54:40 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 03:25:39 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)src);
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
