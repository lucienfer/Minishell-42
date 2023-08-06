/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:27:15 by tbelleng          #+#    #+#             */
/*   Updated: 2023/05/30 15:14:31 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	only_error(char *err)
{
	perror(err);
}

int	only_file(t_pars **pars)
{
	t_pars	*tmp;

	tmp = *pars;
	while ((*pars) != NULL)
	{
		if ((*pars)->token != R_INPUT
			&& (*pars)->token != R_OUTPUT && (*pars)->token != R_DOUTPUT
			&& (*pars)->token != ARG && (*pars)->token != PIPE)
		{
			*pars = tmp;
			return (0);
		}
		(*pars) = (*pars)->next;
	}
	*pars = tmp;
	return (1);
}

static void	creating_file(t_pars **pars, int opening)
{
	while ((*pars) != NULL)
	{
		if ((*pars)->token == R_INPUT)
		{
			opening = open((*pars)->next->str, O_RDONLY);
			if (opening < 0)
			{
				only_error(ERR_INFILE);
				break ;
			}
			close(opening);
		}
		if ((*pars)->token == R_OUTPUT || (*pars)->token == R_DOUTPUT)
		{
			opening = open((*pars)->next->str, O_TRUNC | O_CREAT | O_RDWR,
					0000644);
			if (opening < 0)
			{
				only_error(ERR_OUTFILE);
				break ;
			}
			close(opening);
		}
		(*pars) = (*pars)->next;
	}
}

void	only_file_handler(t_pars **pars)
{
	int		opening;
	t_pars	*tmp;

	tmp = *pars;
	opening = 0;
	creating_file(pars, opening);
	*pars = tmp;
	return ;
}
