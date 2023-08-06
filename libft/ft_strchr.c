/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:19:11 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/16 11:38:15 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == 0)
		return ((char *)s + i);
	return (0);
}

/*int	main()
{
	const char	s[] = "bonjour";
	int	c = 68

	printf("%s\n", strchr(s, c))
	printf("%s\n", ft_strchr(s, c))
}*/
