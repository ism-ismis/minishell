/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getflag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum </var/mail/yyamagum>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 08:23:23 by yyamagum          #+#    #+#             */
/*   Updated: 2021/06/09 08:35:57 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	get_num(char *s, va_list args, t_va *va_data)
{
	int	n;

	n = 0;
	while (s[va_data->index] == '*')
	{
		n = va_arg(args, int);
		va_data->index++;
	}
	if ('0' <= s[va_data->index] && s[va_data->index] <= '9')
		n = ft_atoi_count(&s[va_data->index], va_data);
	while (s[va_data->index] == '*')
	{
		n = va_arg(args, int);
		va_data->index++;
	}
	return (n);
}

void	get_len(char *s, va_list args, t_va *va_data)
{
	if (s[va_data->index] == '.')
	{
		va_data->index++;
		va_data->len = get_num(s, args, va_data);
		if (va_data->len < 0)
			va_data->len = -1;
	}
}

void	get_flag(char *s, va_list args, t_va *va_data)
{
	while (s[va_data->index] == '0' || s[va_data->index] == '-'
		|| s[va_data->index] == ' ')
	{
		if (s[va_data->index] == '-')
			va_data->sign = -1;
		if (s[va_data->index] == '0')
			va_data->blank = '0';
		if (s[va_data->index++] == ' ')
			write(1, " ", 1);
	}
	if (('0' <= s[va_data->index] && s[va_data->index] <= '9')
		|| s[va_data->index] == '*')
	{
		va_data->width = get_num(s, args, va_data);
		if (va_data->width < 0)
			va_data->sign = -1;
		if (va_data->width < 0)
			va_data->width *= -1;
	}
	get_len(s, args, va_data);
	while (s[va_data->index] == '.' || s[va_data->index] == '-'
		|| s[va_data->index] == '0')
		va_data->index++;
}
