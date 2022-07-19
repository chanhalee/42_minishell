#include "../include/command_parse.h"
#include <stdlib.h>
#include <errno.h>

void	ft_redirection(t_cmd *cmd);
void	interprete_exe_name(t_cmd *cmd);

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
	int	fds[2];
	
	if (pipe(fds))
		exit(1);
	pid = fork();
	if (pid < 0)
		fork_fail();
	else if (pid > 0)
	{
		close(fds[0]);
		dup2(g_state.std_out, fds[1]);
		close(fds[1]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	else
	{
		dup2(fds[0], g_state.std_in);
		close(fds[0]);
		close(fds[1]);
		execve(cmd->argv[0], cmd->argv, NULL);
	}
}

void	ft_exec(t_cmd_list *lists)
{
	t_cmd	*cmd;
	int		pipe_open;

	cmd = lists->cmd_list;
	while (cmd != NULL)
	{	
		ft_redirection(cmd);
		check_exec_name_is_builtin(cmd);
		pipes(cmd);
		dup2(g_state.std_in, STDIN);
		dup2(g_state.std_out, STDOUT);
		cmd = cmd->next;
	}
}