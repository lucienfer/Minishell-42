/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:16:14 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/09 08:25:12 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp = (char *) dest;
	tmp2 = (char *) src;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (dest);
}
