/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_one_cmdd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:53:18 by tbelleng          #+#    #+#             */
/*   Updated: 2023/05/31 16:39:02 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_arg(t_pipe *file)
{
	int	i;

	i = -1;
	if (file->cmd_paths)
	{
		while (file->cmd_paths[++i])
			free(file->cmd_paths[i]);
		free(file->cmd_paths);
	}
	i = -1;
	if (file->cmd_to_exec)
	{
		while (file->cmd_to_exec[++i])
			free(file->cmd_to_exec[i]);
		free(file->cmd_to_exec);
	}
	if (file->cmd)
		free(file->cmd);
}

void	parent_free_one(t_pipe *file)
{
	int		i;
	t_node	*tmp;

	i = -1;
	if (file->infile > 0)
		close(file->infile);
	if (file->outfile != 1)
		close(file->outfile);
	free_arg(file);
	while (file->node)
	{
		tmp = file->node->next;
		free(file->node);
		file->node = tmp;
	}
	free(file->paths);
}

void	free_one_cmd_infile(t_pars **pars, t_pipe *file, t_data *data)
{
	int		i;
	t_node	*node;

	i = -1;
	while (data->env[++i])
		free(data->env[i]);
	free(data->env);
	free_arg(file);
	free(file->paths);
	while (file->node)
	{
		node = file->node->next;
		close(file->node->fd[0]);
		free(file->node);
		file->node = node;
	}
	free_pars(pars);
}

void	free_one_cmd_isfile(t_pars **pars, t_pipe *file, t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
		free(data->env[i]);
	free(data->env);
	free(file->cmd_args);
	i = -1;
	if (file->cmd_paths)
	{
		while (file->cmd_paths[++i])
			free(file->cmd_paths[i]);
		free(file->cmd_paths);
	}
	free(file->cmd_to_exec[0]);
	free(file->cmd_to_exec);
	free(file->paths);
	free_nodess(file);
	free_pars(pars);
}

void	free_one_cmd_nofound(t_pars **pars, t_pipe *file, t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
		free(data->env[i]);
	free(data->env);
	free(file->cmd_args);
	i = -1;
	if (file->cmd_paths)
	{
		while (file->cmd_paths[++i])
			free(file->cmd_paths[i]);
		free(file->cmd_paths);
	}
	i = -1;
	while (file->cmd_to_exec[++i])
		free(file->cmd_to_exec[i]);
	free(file->cmd_to_exec);
	free(file->cmd);
	free(file->paths);
	free_nodess(file);
	free_pars(pars);
}
