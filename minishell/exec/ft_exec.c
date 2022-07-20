#include "../include/command_parse.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void	ft_redirection(t_cmd *cmd);
int		interprete_exe_name(t_cmd *cmd);

void	fork_fail(void)
{
	printf("fork fail\n");
	exit(TYPE_FAIL);
}

void	set_pipe(t_cmd *cmd)
{
	if (cmd->type == TYPE_PIPE
		|| (cmd->next != 0 && cmd->next->type == TYPE_PIPE))
	{
		if (cmd->type != TYPE_PIPE)
			dup2(cmd->fds[1], 1);
		else if (cmd->next == 0)
			dup2(cmd->prev->fds[0], 0);
		else
		{
			dup2(cmd->prev->fds[0], 0);
			dup2(cmd->fds[1], 1);
		}
	}
}

void	close_fd(t_cmd *cmd, int *stin, int *stout)
{
	if (cmd->prev != 0)
		close(cmd->prev->fds[0]);
	close(cmd->fds[1]);
	if (cmd->next == 0)
		close(cmd->fds[0]);
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
	dup2(*stin, 0);
	dup2(*stout, 1);
	close(*stin);
	close(*stout);
}

void	pipes(t_cmd *cmd)
{
	int	pid;
	int	ret;
	int	status;

	g_state.is_fork = 1;
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		set_pipe(cmd);
		if (cmd->fd_in != 0)
			dup2(cmd->fd_in, 0);
		if (cmd->fd_out != 1)
			dup2(cmd->fd_out, 1);
		ret = exec_builtin(cmd);
		if (ret == -1)
			ret = execve(cmd->argv[0], cmd->argv, NULL);
		exit(ret);
	}
	else
	{
		close(cmd->fds[1]);
		wait(&status);
		g_state.exit_code = WEXITSTATUS(status);
	}
}

void	set_type(t_cmd_list *lists)
{
	t_cmd	*cmd;

	cmd = lists->cmd_list;
	cmd->type = TYPE_NORMAL;
	cmd = cmd->next;
	while(cmd != NULL)
	{
		cmd->type = TYPE_PIPE;
		cmd = cmd->next;
	}
}

int	ft_exec(t_cmd_list *lists)
{
	t_cmd	*cmd;
	int		pipe_open;
	int		path_exec;
	int		builtin_exec;
	int		std_in;
	int		std_out;

	set_type(lists);
	cmd = lists->cmd_list;
	while (cmd != NULL)
	{
		std_out = dup(STDOUT);
		std_in = dup(STDIN);	
		pipe(cmd->fds);
		if (cmd->argv[0][0] == '\0')
		{
			cmd = cmd->next;
			continue;
		}
		builtin_exec = check_exec_name_is_builtin(cmd);
		path_exec = interprete_exe_name(cmd);
		// printf("path_exec = %d, builtin_exec = %d\n", path_exec, builtin_exec);
		if (builtin_exec == 1)
		{
			ft_redirection(cmd);
			exec_builtin(cmd);
		}
		else if (path_exec == 3)
			printf("bash: %s: is a directory\n", cmd->argv[0]);
		else if (builtin_exec == 0 || path_exec == 0)
		{
			ft_redirection(cmd);
			pipes(cmd);
			close_fd(cmd, &std_in, &std_out);
			if (g_state.exit_code == 34 && cmd->prev == NULL)
				return (34);
			g_state.is_fork = 0;
		}
		else
		{
			if (builtin_exec == -1 && path_exec == -1)
				printf("bash: %s: command not found\n", cmd->argv[0]);
			else if (builtin_exec == -1 && path_exec == 1)
				printf("bash: %s: No such file or directory\n", cmd->argv[0]);
			g_state.exit_code = 127;
		}
		cmd = cmd->next;
	}
	return (0);
}
