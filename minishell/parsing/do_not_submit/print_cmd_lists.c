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
	printf("++ cmd_input: {%s}\n", *(cmd->input_buffer));
	index = -1;
	if (cmd->argv != NULL)
	{
		while ((cmd->argv)[++index] != NULL)
			printf("++ cmd_argv[%d]: {%s}\n", index, (cmd->argv)[index]);
	}
	index = -1;
	if(cmd->path != NULL)
	{
		while ((cmd->path)[++index] != NULL)
			printf("++ cmd_path[%d]: {%s}\n",  index, (cmd->path)[index]);
	}
	index = -1;
	if (cmd->redirection_list != NULL)
	{
		red = cmd->redirection_list;
		while (red != NULL){
			printf("++ cmd_redlist[%d]: (%d)%s\n",  ++index, red->red_type,red->file);
			red = red->next;
		}
	}
	printf("++ cmd_output: {%s}\n", cmd->output_buffer);
}

void print_cmd_lists(t_cmd_list *lists)
{
	int			cmd_counter;
	t_cmd_list	*p;
	t_cmd		*cmd;

	cmd_counter = -1;
	printf ("\n=======print_cmd_list========\n");
	printf("+ list_status: %d\n", lists->status);
	printf("+ list_first_input: {%s}\n\n", lists->first_cmd_input);
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
