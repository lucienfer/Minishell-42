/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:51:53 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/15 18:38:17 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stddef.h>
//#include <string.h>
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	if (s == d)
		return (dest);
	if (s > d)
	{
		while (n > 0)
		{
			d[i] = s[i];
			i++;
			n--;
		}
		return (dest);
	}
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (dest);
}

/*#include <stdio.h>
int	main()
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	src1[] = "lorem ipsum dolor sit amet";
	char	*dest;
	char	*dest1;

	dest = src + 1;
	printf("%s\n", (char *) ft_memmove(src, dest, 8));
	dest1 = src1 + 1;
	printf("%s\n", (char *)memmove(src1, dest1, 8));
}*/
