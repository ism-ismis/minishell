/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamagum <yyamagum@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 03:59:26 by yyamagum          #+#    #+#             */
/*   Updated: 2021/05/24 03:38:12 by yyamagum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_return;
	t_list	*cpy;

	if (!lst || !f)
		return (NULL);
	f_return = ft_lstnew(f(lst->content));
	if (!f_return)
		return (NULL);
	cpy = f_return;
	while (lst->next)
	{
		lst = lst->next;
		f_return->next = ft_lstnew(f(lst->content));
		if (!f_return->next)
		{
			ft_lstclear(&cpy, del);
			return (NULL);
		}
		f_return = f_return->next;
	}
	return (cpy);
}
