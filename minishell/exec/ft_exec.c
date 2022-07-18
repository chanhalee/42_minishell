#include "../include/command_parse.h"

void	ft_redirection(t_cmd *cmd);

void	redir(t_cmd_list *lists)
{
	t_cmd	*cmd;
	cmd = lists->cmd_list;
	
	while (cmd != NULL)
	{
		ft_redirection(cmd);
		cmd = cmd->next;
	}
}

void ft_exec(t_cmd_list *lists)
{
	t_cmd		*cmd;

	redir(lists);
	while (cmd != NULL)
	{
		check_exec_name_is_builtin(cmd);
		// output_redir(cmd);
		cmd = cmd->next;
	}
	dup2(g_state.fd_in, STDIN);
	dup2(g_state.fd_out, STDOUT);
}