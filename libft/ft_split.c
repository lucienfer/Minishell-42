/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:53:08 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/16 11:10:29 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (0);
}

static int	word_count(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (str[i] && str[i] != charset)
			count++;
		while (str[i] && str[i] != charset)
			i++;
	}
	return (count + 1);
}

static int	word_length(const char *str, char charset, char **tab, int length)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (str[i])
	{
		len = 0;
		while (str[i] && str[i] == charset)
			i++;
		while (str[i] && str[i] != charset)
		{
			i++;
			len++;
		}
		if (j < length)
		{
			tab[j] = malloc(sizeof(char) * len + 1);
			if (!tab[j])
				return (ft_free(tab, j - 1));
			j++;
		}
	}
	return (1);
}

static void	word_write(const char *str, char charset, char **tab, int length)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] && str[i] == charset)
			i++;
		while (str[i] && str[i] != charset)
		{
			tab[j][k] = str[i];
			k++;
			i++;
		}
		if (j < length)
		{
			tab[j][k] = 0;
			j++;
		}
	}
	tab[j] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		len;

	len = word_count(s, c);
	tab = malloc(sizeof(char *) * len);
	if (!tab)
		return (0);
	if (!word_length(s, c, tab, len - 1))
		return (0);
	word_write(s, c, tab, len - 1);
	return (tab);
}
