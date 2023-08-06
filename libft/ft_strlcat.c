/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:58:59 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/16 11:42:07 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stddef.h>
//#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		u;

	u = 0;
	i = 0;
	while (dst[i] != 0)
		i++;
	if (size > i + 1)
	{
		while (src[u] != '\0' && i + u < size - 1)
		{
			dst[i + u] = src[u];
			u++;
		}
		dst[i + u] = '\0';
	}
	if (size >= i)
		return (i + ft_strlen(src));
	return (ft_strlen(src) + size);
}

//#include <stdio.h>
/*int	main(void)
{
	char	dest[] = "salut";
	const char	src[] = "bonjour";
	size_t		i = 3;
	size_t result = strlcat(dest, src, i);

	printf("%d\n", (int)ft_strlcat(dest, src, i));
	printf("%ld\n", result);

}*/
