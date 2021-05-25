/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:00:36 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 03:50:55 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cut_point(char *str, char c, int i)
{
	int	j;

	j = i;
	while (str[j] != '\0')
	{
		if (str[j] == c)
			return (j);
		j++;
	}
	return (j);
}

static char	**allocate_str_arr(char *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**str_arr;

	if (!s)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		j = ft_cut_point((char *)s, c, i);
		if (i < j)
		{
			i = j;
			index++;
		}
		else
			i++;
	}
	if (index == 0)
		return (ft_zero_arr());
	str_arr = (char **)malloc((index + 1) * sizeof(char *));
	return (str_arr);
}

static void	*ft_input(char **str_arr, int index, char *str, int len)
{
	int		k;

	str_arr[index] = (char *)malloc((len + 1) * sizeof(char));
	if (!str_arr[index])
	{
		k = 0;
		while (k < index)
			free(str_arr[k]);
		free(str_arr);
		return (NULL);
	}
	k = 0;
	while (k < len)
	{
		str_arr[index][k] = str[k];
		k++;
	}
	str_arr[index][k] = '\0';
	return ((void *)(str_arr[index]));
}

static char	**ft_zero_arr(void)
{
	char	**str_arr;

	str_arr = (char **)malloc(sizeof(char *));
	if (!str_arr)
		return (NULL);
	str_arr[0] = 0;
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	char	*str;
	int		i;
	int		j;
	int		index;

	str_arr = allocate_str_arr;
	if (!str_arr)
		return (NULL);
	i = -1;
	index = 0;
	while (str[++i] != '\0')
	{
		j = ft_cut_point(str, c, i);
		if (i < j)
		{
			if (!ft_input(str_arr, index++, &str[i], j - i))
				return (NULL);
			i = j - 1;
		}
	}
	str_arr[index] = NULL;
	return (str_arr);
}
