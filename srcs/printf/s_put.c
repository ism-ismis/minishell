/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_put.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 01:23:28 by yyamagum          #+#    #+#             */
/*   Updated: 2021/06/09 07:59:35 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"

static	int	ftprintf_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

void	ft_putstr_len(char *s, int len)
{
	int	i;

	if (!s)
	{
		i = len;
		if (i > 6)
			i = 6;
		write(1, "(null)", i);
		return ;
	}
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	put_blank(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

void	put_s(t_va *va_data, char *arg)
{
	int	len;
	int	len_blank;

	if (va_data->blank == -1)
		va_data->blank = ' ';
	len = 0;
	if (arg)
		len = ftprintf_strlen(arg);
	else
		len = 6;
	if (va_data->len >= 0 && len > va_data->len)
		len = va_data->len;
	len_blank = va_data->width - len;
	if (va_data->sign != -1)
		put_blank(va_data->blank, len_blank);
	ft_putstr_len(arg, len);
	if (va_data->sign == -1)
		put_blank(' ', len_blank);
	if (len_blank > 0)
		len += len_blank;
	va_data->len = len;
}
