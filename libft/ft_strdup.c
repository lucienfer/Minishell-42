/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:28:56 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/15 11:33:22 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		u;
	char	*str;

	i = 0;
	u = 0;
	while (s[i])
		i++;
	str = malloc((sizeof (char)) * i + 1);
	if (!str)
		return (0);
	while (i - u > 0)
	{
		str[u] = s[u];
		u++;
	}
	str[i] = '\0';
	return (str);
}
