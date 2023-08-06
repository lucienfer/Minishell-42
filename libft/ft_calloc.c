/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:15:44 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/15 18:17:10 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*str;
	size_t	i;

	total = nmemb * size;
	if (nmemb && total / nmemb != size)
		return (0);
	str = malloc(total);
	if (!str)
		return (0);
	i = 0;
	while (i < total)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
