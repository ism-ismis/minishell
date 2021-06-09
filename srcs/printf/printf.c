/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:41:11 by yyamagum          #+#    #+#             */
/*   Updated: 2021/06/09 08:29:12 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	va_init(t_va *va_data)
{
	va_data->type = 0;
	va_data->sign = 0;
	va_data->blank = -1;
	va_data->width = -1;
	va_data->len = -1;
	va_data->index = 1;
}

void	put_va(char *s, va_list args, t_va *va_data)
{
	get_flag(s, args, va_data);
	va_data->type = s[va_data->index];
	if (s[va_data->index] == 'c')
		put_c(va_data, va_arg(args, int));
	else if (va_data->type == 's')
		put_s(va_data, va_arg(args, char *));
	else if (va_data->type == 'p')
		put_p(va_data, va_arg(args, long));
	else if (va_data->type == 'd' || s[va_data->index] == 'i')
		put_number(va_data, va_arg(args, int), 10);
	else if (va_data->type == 'u')
		put_number(va_data, va_arg(args, unsigned int), 10);
	else if (va_data->type == 'x')
		put_number(va_data, va_arg(args, int), 16);
	else if (va_data->type == 'X')
		put_number(va_data, va_arg(args, int), 16);
	else if (va_data->type == '%')
		put_per(va_data);
	else
		return ;
	va_data->index++;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		count;
	t_va	va_data;

	va_start(args, s);
	len = 0;
	count = 0;
	while (s[len] != '\0')
	{
		if (s[len] == '%')
		{
			va_init(&va_data);
			put_va((char *)&s[len], args, &va_data);
			count += va_data.len - va_data.index;
			len += va_data.index;
		}
		else
		{
			write(1, &s[len], 1);
			len++;
		}
	}
	va_end(args);
	return (len + count);
}
