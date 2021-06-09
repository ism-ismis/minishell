/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 00:11:46 by yyamagum          #+#    #+#             */
/*   Updated: 2021/06/09 07:58:46 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"

static int	set_len(t_va *va_data, long arg)
{
	int		len;
	long	i;

	if (va_data->blank == -1)
		va_data->blank = ' ';
	len = 4;
	i = 1;
	while (arg / i != 0)
	{
		i *= 16;
		len++;
	}
	if (len < va_data->len)
		len = va_data->len;
	if (len == 9)
		len += 2;
	if (arg == 0 && va_data->len == 0)
		len = 2;
	else if (arg == 0)
		len = va_data->len + 4;
	return (len);
}

void	put_prefix(t_va *va_data, long arg)
{
	write(1, "0x", 2);
	if (arg == 0 && va_data->len != 0)
	{
		write(1, "0", 1);
		put_blank('0', va_data->len - 1);
	}
}

void	put_p(t_va *va_data, long arg)
{
	int	len;
	int	len_blank;

	len = set_len(va_data, arg);
	len_blank = va_data->width - len;
	if (va_data->sign != -1)
		put_blank(' ', len_blank);
	put_prefix(va_data, arg);
	if (arg != 0)
	{
		if (len == 11 && va_data->len == 9)
			write(1, "0", 1);
		if (len == 11 && va_data->len > 9)
			write(1, "1", 1);
		ft_putptr(arg, len - 3);
	}
	if (va_data->sign == -1)
		put_blank(' ', len_blank);
	if (len_blank > 0)
		len += len_blank;
	if (!arg && va_data->len > 0)
		len -= 2;
	va_data->len = len;
}
