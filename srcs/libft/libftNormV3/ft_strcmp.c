/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:50:54 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 02:29:51 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*us_s1;
	unsigned char	*us_s2;

	us_s1 = (unsigned char *)s1;
	us_s2 = (unsigned char *)s2;
	if (!us_s1 || !us_s1)
		return (-1);
	i = 0;
	while (us_s1[i] == us_s2[i])
	{
		if (us_s1[i] == '\0')
			return (0);
		i++;
	}
	return (us_s1[i] - us_s2[i]);
}
