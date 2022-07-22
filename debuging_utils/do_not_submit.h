#ifndef DO_NOT_SUBMIT_H
# define DO_NOT_SUBMIT_H

# include <stdio.h>
# include "../minishell/include/command_parse.h"

void	print_cmd_lists(t_cmd_list *lists);
void	print_token_list(t_parse_token *list);

#endif