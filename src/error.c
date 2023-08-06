/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:48:02 by tbelleng          #+#    #+#             */
/*   Updated: 2023/05/31 17:15:15 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_global;

int	msg(char *err, int i)
{
	write(2, err, ft_strlen(err));
	g_global = i;
	return (1);
}

void	msg_error(char *err, t_pipe *file)
{
	perror(err);
	if (file->infile != -1 && file->infile != 0)
		close(file->infile);
}

void	close_pipes(t_pipe *file)
{
	close_here_doc_pipe(file->node, 1, 0);
	close(file->fd[0]);
	close(file->fd[1]);
	if (file->prev_pipes != -1)
		close(file->prev_pipes);
}

static void	free_part(t_pipe *file)
{
	t_node	*tmp;

	if (file->cmd_args)
		free(file->cmd_args);
	if (file->cmd_paths)
		free(file->cmd_paths);
	while (file->node)
	{
		tmp = file->node->next;
		free(file->node);
		file->node = tmp;
	}
}

void	parent_free(t_pipe *file)
{
	int	i;

	i = -1;
	if (file->infile > 0)
		close(file->infile);
	if (file->outfile != 1)
		close(file->outfile);
	if (file->cmd_paths)
	{
		while (file->cmd_paths[++i])
			free(file->cmd_paths[i]);
	}
	free_part(file);
	i = -1;
	if (file->cmd_to_exec)
	{
		while (file->cmd_to_exec[++i])
			free(file->cmd_to_exec[i]);
	}
	free(file->cmd_to_exec);
	free(file->cmd);
	free(file->paths);
	free(file->pid);
}
