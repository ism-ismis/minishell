/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:45:21 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 03:28:18 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*f_return;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	len = ft_strlen((char *)s);
	f_return = (char *)malloc((len + 1) * sizeof(char));
	if (!f_return)
		return (NULL);
	i = 0;
	while (i < len)
	{
		f_return[i] = (f)(i, s[i]);
		i++;
	}
	f_return[i] = '\0';
	return (f_return);
}
