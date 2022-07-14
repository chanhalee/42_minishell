/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_add_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:25:37 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/15 00:50:18 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

void	*parse_t_cmd_add_argv(t_cmd *cmd, char *str, int index)
{
	char	**new_argv;
	char	*new_str;
	int		counter;

	counter = -1;
	if (index == 0)
	{
		new_str = ft_strdup(str);
		if (new_str == NULL)
			return (NULL);
		cmd->exec_file_name = new_str;
	}
	new_str = ft_strdup(str);
	while(cmd->argv[++counter] != NULL)
		;
	new_argv = (char **)malloc(sizeof(char *) * (counter + 2));
	if (new_argv == NULL || new_str == NULL)
		return (parse_safe_free_multi_str(new_argv, new_str, NULL, NULL));
	counter = -1;
	while(cmd->argv[++counter] != NULL)
		new_argv[counter] = cmd->argv[counter];
	new_argv[counter] = new_str;
	new_argv[counter + 1] = NULL;
	parse_safe_free_two_d_char(cmd->argv, -1);
	cmd->argv = new_argv;
	return (NULL);
}