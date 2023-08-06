/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:05:28 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/11 17:45:09 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(src);
	while (size != 0 && i < size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = 0;
	return (len);
}
