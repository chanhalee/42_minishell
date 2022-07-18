#include "../include/command_parse.h"

void ft_exec(t_cmd_list *lists)
{
	t_cmd		*cmd;

	cmd = lists->cmd_list;
	while (cmd != NULL)
	{
		check_exec_name_is_builtin(cmd);
		cmd = cmd->next;
	}
}