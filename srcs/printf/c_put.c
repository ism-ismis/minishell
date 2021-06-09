/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_put.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:58:24 by yyamagum          #+#    #+#             */
/*   Updated: 2021/06/09 07:43:59 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"

void	put_c(t_va *va_data, char arg)
{
	int	len;
	int	len_blank;

	len = 1;
	len_blank = va_data->width - len;
	if (va_data->sign != -1)
		put_blank(' ', len_blank);
	write(1, &arg, 1);
	if (va_data->sign == -1)
		put_blank(' ', len_blank);
	if (len_blank > 0)
		len += len_blank;
	va_data->len = len;
}
