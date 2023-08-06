/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:53:27 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/15 18:20:14 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*next;

	if (!*lst)
		return ;
	elem = *lst;
	while (elem != 0)
	{
		next = elem->next;
		(*del)(elem->content);
		free(elem);
		elem = next;
	}
	*lst = 0;
}
