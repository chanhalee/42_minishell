/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:47:46 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:55 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

void	free_t_cmd_redirection(t_cmd *cmd);

void	free_first_t_cmd_node(t_cmd_list *cmd_list)
{
	t_cmd	*node;
	int		index;

	if (cmd_list == NULL || cmd_list->cmd_list == NULL)
		return ;
	node = cmd_list->cmd_list;
	cmd_list->cmd_list = cmd_list->cmd_list->next;
	free_t_cmd_redirection(node);
	if (node->exec_file_path != NULL)
		free (node->exec_file_path);
	index = -1;
	while (node->environment != NULL && (node->environment)[++index])
		free (node->environment);
	if (node->environment != NULL)
		free (node->environment);
	index = -1;
	while (node->argv != NULL && (node->argv)[++index])
		free((node->argv)[index]);
	if (node->argv != NULL)
		free (node->argv);
	if (node->output_buffer)
		free (node->output_buffer);
	free (node);
}

void	free_t_cmd_redirection(t_cmd *cmd)
{
	t_cmd_redirection	*cmd_red_prev;

	while (cmd->redirection_list != NULL)
	{
		if (cmd->redirection_list->file != NULL)
			free(cmd->redirection_list->file);
		cmd_red_prev = cmd->redirection_list;
		free (cmd_red_prev);
		cmd->redirection_list = cmd->redirection_list->next;
	}
}

void	free_t_cmd_list(t_cmd_list *cmd_list)
{
	if (cmd_list == NULL)
		return ;
	if (cmd_list->first_cmd_input != NULL)
		free (cmd_list->first_cmd_input);
	while (cmd_list->cmd_list != NULL)
		free_first_t_cmd_node(cmd_list);
	free (cmd_list);
}
