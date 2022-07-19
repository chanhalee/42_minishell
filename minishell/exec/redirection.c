/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:07:22 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/19 21:16:24 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	ft_redirection(t_cmd *cmd)
{
	t_cmd_redirection	*red;
	int					output_fd;
	int					input_fd;

	g_state.std_out = dup(STDOUT);
	g_state.std_in = dup(STDIN);
	red = cmd->redirection_list;
	while (red != NULL)
	{
		if (red->red_type == TYPE_TOKEN_IO_R)
			g_state.fd_out = open(red->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (red->red_type == TYPE_TOKEN_IO_RR)
			g_state.fd_out = open(red->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (red->red_type == TYPE_TOKEN_IO_L)
			g_state.fd_in = open(red->file, O_RDONLY);
		if (g_state.fd_out == -1 || g_state.fd_in == -1)
		{
			printf("bash: %s: No such file or directory\n", red->file);
			g_state.exit_code = 127;
		}
		if (red->red_type == TYPE_TOKEN_IO_R || red->red_type == TYPE_TOKEN_IO_RR)
			dup2(g_state.fd_out, STDOUT);
		else if (red->red_type == TYPE_TOKEN_IO_L)
			dup2(g_state.fd_in, STDIN);
		red = red->next;
	}
}