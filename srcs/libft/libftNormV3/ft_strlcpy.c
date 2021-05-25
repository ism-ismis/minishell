/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:50:35 by yyamagum          #+#    #+#             */
/*   Updated: 2020/11/22 13:59:52 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen((char *)src);
	i = 0;
	while (src[i] != '\0' && i + 1 < dest_size)
	{
		dest[i] = src[i];
		i++;
	}
	if (dest_size != 0)
		dest[i] = '\0';
	return (len);
}
