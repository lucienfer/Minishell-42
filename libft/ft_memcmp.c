/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:33:52 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/15 18:29:50 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <string.h>
//#include <stddef.h>
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				u;
	unsigned char	*tmp;
	unsigned char	*tmp2;

	i = 0;
	u = 0;
	tmp = (unsigned char *) s1;
	tmp2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	if (tmp[i] == 0 && tmp2[i] != 0)
		return (-1);
	while (i < n)
	{
		if (tmp[i] != tmp2[i])
			return (tmp[i] - tmp2[i]);
		i++;
	}
	return (u);
}

/*int	main()
{
	char	s1[] = {-128, 0, 127, 0};
	char	s2[] = {0, 0, 17, 0};
	size_t	n = 4;

	printf("%d\n", ft_memcmp(s2, s1, n));
}*/
