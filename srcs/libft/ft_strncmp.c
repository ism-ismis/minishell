/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:50:54 by yyamagum          #+#    #+#             */
/*   Updated: 2020/11/22 13:19:28 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us_s1;
	unsigned char	*us_s2;

	if (n == 0)
		return (0);
	us_s1 = (unsigned char *)s1;
	us_s2 = (unsigned char *)s2;
	i = 0;
	while (us_s1[i] == us_s2[i])
	{
		if (us_s1[i] == '\0' || i + 1 == n)
			return (0);
		i++;
	}
	return (us_s1[i] - us_s2[i]);
}
