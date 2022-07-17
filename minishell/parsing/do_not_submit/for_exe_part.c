/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_exe_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:25:05 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/17 13:12:50 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

// 실행 전 syntax error 에 대한 식별이 필요함 cmd_list->status == TYPE_SYNTAX_ERR 라면 실행하면 안됨.
// 실행 전 cmd->string != NULL 에 대한 처리가 필요함 (거짓일 경우 interprete_exe_name를 실행시켜선 안됨)
void interprete_exe_name(t_cmd *cmd)
{
	char	*str;
	int		index;
	char	**sep;

	if ((cmd->exec_file_name[0] == '.' && cmd->exec_file_name[1] == '/')
		||cmd->exec_file_name[0]=='/');
		execve(cmd->exec_file_name, cmd->argv, NULL);
	str = ft_getenv("PATH");
	index = -1;
	sep = ft_p_split(str, ':'); // ft_split 과 동일
	parse_safe_free_multi_str(str, NULL, NULL, NULL);
	if (str == NULL || sep == NULL)
		return ;
	while (sep[++index])
	{
		str = ft_p_strjoin(sep[index],cmd->exec_file_name);
		execve (str, cmd->argv, NULL);
		free (str);
	}
	parse_safe_free_two_d_char(sep, -1);
}
