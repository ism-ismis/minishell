/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:20:24 by yyamagum          #+#    #+#             */
/*   Updated: 2020/11/22 16:31:06 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_cpy;
	size_t	len;
	size_t	i;
	char	cc;

	s_cpy = (char *)s;
	cc = (char)c;
	len = ft_strlen(s_cpy);
	i = len;
	while (s_cpy[i] != cc)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (&(s_cpy[i]));
}
