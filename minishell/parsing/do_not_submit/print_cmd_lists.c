/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:27:09 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/11 16:32:55 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./do_not_submit.h"

void print_cmd(t_cmd *cmd, int list_counter, int cmd_counter)
{
	int	index;

	printf("+++ [%d] [%d] cmd_path: %s\n",list_counter, cmd_counter, cmd->exec_file_path);
	index = -1;
	printf("+++ [%d] [%d] cmd_input: %s\n",list_counter, cmd_counter, *(cmd->input_buffer));
	if (cmd->argv != NULL)
	{
		while ((cmd->argv)[++index] != NULL)
			printf("+++ [%d] [%d] cmd_argv[%d]: %s\n",list_counter, cmd_counter, index, (cmd->argv)[index]);
	}
	index = -1;
	if(cmd->environment != NULL)
	{
		while ((cmd->environment)[++index] != NULL)
			printf("+++ [%d] [%d] cmd_invinronment[%d]: %s\n",list_counter, cmd_counter, index, (cmd->environment)[index]);
	}
	printf("+++ [%d] [%d] cmd_output: %s\n",list_counter, cmd_counter, cmd->output_buffer);
}

void print_cmd_lists(t_cmd_list *lists)
{
	int			list_counter;
	int			cmd_counter;
	t_cmd_list	*p;
	t_cmd		*cmd;


	list_counter = -1;
	while(lists != NULL)
	{
		list_counter++;
		printf("++ [%d] list_status: %d\n", list_counter, lists->status);
		printf("++ [%d] list_first_input: %s\n", list_counter, lists->first_cmd_input);
		cmd_counter = -1;
		cmd = lists->cmd_list;
		while (cmd != NULL)
		{
			cmd_counter++;
			print_cmd(cmd, list_counter, cmd_counter);
			cmd = cmd->next;
		}
		lists = lists->next_list;
	}
}
