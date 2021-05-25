/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:20:24 by yyamagum          #+#    #+#             */
/*   Updated: 2020/11/20 18:56:56 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;
	char	cc;

	s_cpy = (char *)s;
	cc = (char)c;
	while (*s_cpy != cc)
	{
		if (*s_cpy == '\0')
			return (NULL);
		s_cpy++;
	}
	return (s_cpy);
}
