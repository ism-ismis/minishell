/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:09:40 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 03:22:13 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_itoa_len(int n)
{
	int	len;

	len = -1;
	if (n < 0)
		len++;
	while (++len == 0 || n != 0)
		n /= 10;
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;
	long	n_;

	len = count_itoa_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = len - 1;
	n_ = (long)n;
	if (n_ < 0)
		n_ *= -1;
	while (n_ != 0 || i == len - 1)
	{
		str[i--] = n_ % 10 + '0';
		n_ /= 10;
	}
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	return (str);
}
