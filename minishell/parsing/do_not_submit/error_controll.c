/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_controll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:57:28 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/15 15:03:04 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./do_not_submit.h"

void	emergency_exit_parse(t_cmd *cmd_list, int exit_code)
{
	t_cmd	*next;
	t_cmd	*prev;
	int		index;

	next = cmd_list;
	if (cmd_list == NULL)
		exit(exit_code);
	if (next != NULL && next->input_buffer != NULL)
		free(next->input_buffer);
	while (next != NULL)
	{
		if (next->exec_file_name)
			free(next->exec_file_name);
		if (next->path)
		{
			index = -1;
			while ((next->path)[++index])
				free((next->path)[index]);
			free(next->path);
		}
		if (next->argv)
		{
			index = -1;
			while ((next->argv)[++index])
				free((next->argv)[index]);
			free(next->argv);
		}
		if (next->output_buffer)
			free(next->output_buffer);
		prev = next;
		next = next->next;
		free(prev);
	}
	exit(exit_code);
}