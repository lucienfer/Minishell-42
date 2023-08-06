/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:47:25 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/16 11:44:42 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (start >= ft_strlen(s))
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[i] = '\0';
		return (str);
	}
	if (!s)
		return (0);
	if (len <= ft_strlen(s) - start)
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s) - start) + 1);
	if (!str)
		return (0);
	while (start < ft_strlen(s) && i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
