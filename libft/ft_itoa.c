/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:32:40 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/15 15:20:04 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	long long int	nb;
	int				len;

	len = 1;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_calcul(int i, char *str, long long int nb)
{
	while (nb >= 10)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	str[i] = nb + '0';
}

char	*ft_itoa(int n)
{
	char			*str;
	long long int	nb;
	int				i;

	nb = n;
	i = len(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	ft_calcul(i - 1, str, nb);
	return (str);
}
