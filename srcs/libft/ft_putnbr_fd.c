/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:21:20 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 03:41:57 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_num(int n[10], int i, int fd)
{
	int	m;

	while (i >= 0)
	{
		m = n[i] + '0';
		write(fd, &m, 1);
		i -= 1;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		nbr[10];
	int		i;
	long	n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		write(fd, "-", 1);
		n_long = -1 * n_long;
	}
	i = 0;
	while (n_long != 0 || i == 0)
	{
		nbr[i] = n_long % 10;
		n_long /= 10;
		i += 1;
	}
	i -= 1;
	write_num(nbr, i, fd);
}
