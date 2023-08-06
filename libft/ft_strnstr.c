/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:10:13 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/16 11:43:35 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		u;

	u = 0;
	i = 0;
	while (little[u])
		u++;
	u--;
	if (little[0] == '\0')
		return ((char *)big);
	while (i + u < len && big[i])
	{
		if (big[i] == little[0] && (!ft_strncmp(big + i, little, u + 1)))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
