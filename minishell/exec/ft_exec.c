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

void	pipes(t_cmd *cmd)
{
	int	pid;
	int	ret;
	int	status;
	int	pipes[2];

	g_state.is_fork = 1;
	if (pipe(pipes))
		exit(1);
	pid = fork();
	if (pid < 0)
		fork_fail();
	else if (pid > 0)
	{
		// close(pipes[0]);
		dup2(pipes[1], 1);
		close(pipes[1]);
		ret = wait(&status);
		g_state.exit_code = WEXITSTATUS(status);
	}
	else if (pid == 0)
	{
		dup2(pipes[0], 0);
		// close(pipes[0]);
		close(pipes[1]);
		ret = exec_builtin(cmd);
		if (ret == -1)
			ret = execve(cmd->argv[0], cmd->argv, NULL);
		exit(ret);
	}
}

int	ft_exec(t_cmd_list *lists)
{
	t_cmd	*cmd;
	int		pipe_open;
	int		path_exec;
	int		builtin_exec;

	cmd = lists->cmd_list;
	while (cmd != NULL)
	{
		g_state.std_out = dup(STDOUT);
		g_state.std_in = dup(STDIN);
		builtin_exec = check_exec_name_is_builtin(cmd);
		path_exec = interprete_exe_name(cmd);
		if (builtin_exec == 0 || path_exec == 0)
		{
			ft_redirection(cmd);
			// check_exec_name_is_builtin(cmd);
			pipes(cmd);
			if (g_state.exit_code == 34 && cmd->prev == NULL)
				return (34);
		}
		else
		{
			if (builtin_exec == -1 && path_exec == -1)
				printf("bash: %s: command not found\n", cmd->argv[0]);
			else if (builtin_exec == -1 && path_exec == 1)
				printf("bash: %s: No such file or directory\n", cmd->argv[0]);
			g_state.exit_code = 127;
		}
		dup2(g_state.std_in, STDIN);
		dup2(g_state.std_out, STDOUT);
		g_state.is_fork = 0;
		cmd = cmd->next;
	}
	return (0);
}
