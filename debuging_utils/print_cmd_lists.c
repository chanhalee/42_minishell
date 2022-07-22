/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_lists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:27:09 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/15 17:29:42 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./do_not_submit.h"

void print_cmd(t_cmd *cmd)
{
	int	index;
	t_cmd_redirection *red;

	printf("++ cmd_filename: {%s}\n", cmd->exec_file_name);
	index = -1;
	if (cmd->argv != NULL)
	{
		while ((cmd->argv)[++index] != NULL)
			printf("++ cmd_argv[%d]: {%s}\n", index, (cmd->argv)[index]);
	}
	if (cmd->prev != NULL)
		printf("++ cmd_argv_prev_exec: {%s}\n", cmd->prev->exec_file_name);
	if (cmd->next != NULL)
		printf("++ cmd_argv_next_exec: {%s}\n", cmd->next->exec_file_name);
	index = -1;
	if (cmd->redirection_list != NULL)
	{
		red = cmd->redirection_list;
		while (red != NULL){
			printf("++ cmd_redlist[%d]: (%d)%s\n",  ++index, red->red_type,red->file);
			red = red->next;
		}
	}
}

void print_cmd_lists(t_cmd_list *lists)
{
	int			cmd_counter;
	t_cmd		*cmd;

	cmd_counter = -1;
	printf ("\n=======print_cmd_list========\n");
	printf("+ list_status: %d\n", lists->status);
	if (lists->cmd_list != NULL)
		printf("+ list_first_exec: {%s}\n", lists->cmd_list->exec_file_name);
	if (lists->cmd_list_tail != NULL)
		printf("+ list_last_exec: {%s}\n\n", lists->cmd_list_tail->exec_file_name);
	cmd = lists->cmd_list;
	while (cmd != NULL)
	{
		cmd_counter++;
		printf ("=======[%d]========\n", cmd_counter);
		print_cmd(cmd);
		cmd = cmd->next;
	}
	printf ("====================\n");
}
