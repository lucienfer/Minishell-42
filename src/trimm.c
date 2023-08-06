/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:18:24 by tbelleng          #+#    #+#             */
/*   Updated: 2023/05/31 18:17:01 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_global;

static char	*path_cpy(t_data *data)
{
	int		i;
	int		j;
	int		len;
	char	*path;

	i = 0;
	j = 0;
	while (ft_strncmp("PATH", data->env[i], 4))
		i++;
	while (data->env[i][j] != '=')
		j++;
	j++;
	len = ft_strlen(data->env[i]);
	path = malloc(sizeof(char) * (len - 4));
	if (!path)
		return (NULL);
	len = 0;
	while (data->env[i][j] != '\0')
	{
		path[len] = data->env[i][j];
		len++;
		j++;
	}
	path[len] = '\0';
	return (path);
}

char	*find_path_spe(t_data *data)
{
	int		i;
	int		no_path;
	char	*new;

	i = 0;
	no_path = 0;
	if (!data->env[0])
	{
		msg(NO_PATH, 1);
	}
	while (data->env[i])
	{
		if (ft_strnstr(data->env[i], "PATH", 6) != NULL)
			no_path = 1;
		i++;
	}
	if (no_path == 0)
	{
		return (NULL);
	}
	new = path_cpy(data);
	return (new);
}

static void	is_a_cmd(t_pars **pars, t_pipe *file, t_data *data)
{
	t_pars	*tmp;

	tmp = *pars;
	file->paths = find_path_spe(data);
	if (file->paths)
		file->cmd_paths = ft_split(file->paths, ':');
	while ((*pars) != NULL)
	{
		if ((*pars)->token == BUILTIN)
		{
			file->cmd_nb += 1;
			file->builtin += 1;
		}
		else if ((*pars)->token == CMD)
			file->cmd_nb += 1;
		*pars = (*pars)->next;
	}
	*pars = tmp;
	dup_cmdd(pars, file);
	return ;
}

static int	trimm_end(t_pars **pars, t_pipe file, t_data *data)
{
	int	i;

	i = 0;
	i = pipe_count(pars);
	if (i == 0)
	{
		one_cmd(&file, pars, data);
		return (0);
	}
	else if (i >= 1)
	{
		mult_cmd(&file, pars, data, i);
		return (0);
	}
	return (0);
}

int	trimm_exec(t_pars **pars, t_data *data)
{
	t_pipe	file;

	if (!(*pars)->str[0])
		return (0);
	ft_memset(&file, 0, sizeof(t_pipe));
	init_pars(*pars);
	is_a_cmd(pars, &file, data);
	set_doc(&file, pars);
	here_doc(&file, pars, data);
	trimm_end(pars, file, data);
	return (0);
}
