/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:32:39 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/16 11:30:28 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*last;
	t_list	*src;

	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	src = lst->next;
	while (src != 0)
	{
		last = ft_lstnew((*f)(src->content));
		if (!last)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, last);
		src = src->next;
	}
	return (new);
}
