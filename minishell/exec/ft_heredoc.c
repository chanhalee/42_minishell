/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:55:17 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/21 18:14:44 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"
#include "../include/ft_utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

void	signal_handler(int signo);

void	heredoc_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
    	rl_replace_line("", 1);
    	rl_redisplay();
		kill(pid, SIGTERM);
	}
}

void	go_heredoc(t_cmd_redirection *red, char *eof)
{
	int		fd;
	char	*str;
	int		status;

	fd = open(red->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	signal(SIGINT, heredoc_handler);
	g_state.is_fork = 1;
	pid = fork();
	if (pid == 0)
	{
		while(1)
		{
			str = readline("> ");
			if (str != NULL)
			{
				if (ft_strcmp(eof, str) == 0)
				{
					free(str);
					break ;
				}
				write(fd, str, ft_strlen(str));
				write(fd, "\n", 1);
			}
			else
			{
				printf("\033[1A");
				printf("\033[2C");
				break ;
			}
			free(str);
		}
		exit(1);
	}
	else if (pid > 0)
	{
		wait(&status);
		g_state.exit_code = WEXITSTATUS(status);
	}
	g_state.is_fork = 0;
	signal(SIGINT, signal_handler);
	close(fd);
}

void	rand_file_name(t_cmd_redirection *red, int i)
{
	char	*new_file_name;
	char	*int_to_str;

	int_to_str = ft_itoa(i);
	free(red->file);
	new_file_name = ft_strjoin("./exec/jeounparchanhale", int_to_str);
	red->file = new_file_name;
	free(int_to_str);
}

void	ft_heredoc(t_cmd_list *lists)
{
	t_cmd				*cmd;
	t_cmd_redirection	*red;
	int					i;
	char				*eof;

	cmd = lists->cmd_list;
	i = 0;
	while (cmd != NULL)
	{
		red = cmd->redirection_list;
		while (red != NULL)
		{
			if (red->red_type == TYPE_TOKEN_IO_LL)
			{
				eof = ft_strdup(red->file);
				rand_file_name(red, i);
				red->red_type = BEFORE_LL;
				go_heredoc(red, eof);
				free(eof);
				i++;
			}
			red = red->next;
		}		
		cmd = cmd->next;
	}
}
