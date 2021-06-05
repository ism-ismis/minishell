/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 02:09:38 by yyamagum          #+#    #+#             */
/*   Updated: 2021/01/05 01:27:05 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "limits.h"

typedef struct	s_va
{
	char	type;
	int		sign;
	int		blank;
	int		width;
	int		len;
	int		index;
}				t_va;

int				ft_printf(const char *s, ...);
int				ft_atoi_count(const char *str, t_va *va_data);
void			put_s(t_va *va_data, char *arg);
void			put_c(t_va *va_data, char arg);
void			put_p(t_va *va_data, long arg);
void			put_number(t_va *va_data, long arg, int base);
void			put_x(t_va *va_data, int arg);
void			put_per(t_va *va_data);
void			put_blank(char c, int n);
void			ft_putnbr_base(long nbr, char *base);
void			ft_putptr(long nbr, int len);

#endif
