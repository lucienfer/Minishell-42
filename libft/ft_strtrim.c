/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:09:14 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/16 11:44:19 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		u;
	int		j;
	char	*str;

	j = 0;
	u = 0;
	i = 0;
	while (s1[i])
		i++;
	while (ft_strchr(set, s1[u]))
		u++;
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	if (i == 0)
		u = 1;
	str = malloc((sizeof (char)) * (i - u + 1) + 1);
	while (i - u + 1 > 0)
	{
		str[j] = s1[u];
		j++;
		u++;
	}
	str[j] = '\0';
	return (str);
}
