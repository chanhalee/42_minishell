// #include "../include/command_parse.h"

// void print_cmd_lists_tmp(t_cmd_list *lists)
// {
// 	int			cmd_counter;
// 	t_cmd_list	*p;
// 	t_cmd		*cmd;

// 	cmd_counter = -1;
// 	printf ("\n=======print_cmd_list========\n");
// 	printf("+ list_status: %d\n", lists->status);
// 	printf("+ list_first_input: {%s}\n\n", lists->first_cmd_input);
// 	cmd = lists->cmd_list;
// 	while (cmd != NULL)
// 	{
// 		cmd_counter++;
// 		printf ("=======[%d]========\n", cmd_counter);
// 		print_cmd(cmd);
// 		cmd = cmd->next;
// 	}
// 	printf ("====================\n");
// }