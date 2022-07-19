/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_exe_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:25:05 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/19 16:36:12 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"
#include "../include/ft_builtin.h"

// 실행 전 syntax error 에 대한 식별이 필요함 cmd_list->status == TYPE_SYNTAX_ERR 라면 실행하면 안됨.
// 실행 전 cmd->string != NULL 에 대한 처리가 필요함 (거짓일 경우 interprete_exe_name를 실행시켜선 안됨)
// 실행 전 builtin 함수인지에 대한 확인이 필요하다. (builtin이 참일경우 실행하면 안된다.)
// 위 경우 fork 조차 시켜선 안될듯?
// 하기 interprete_exe_name 함수는 fork 이후에 실행되어야 한다.
int	interprete_exe_name(t_cmd *cmd)
{
	char	*str;
	char	*str_tmp;
	int		index;
	char	**sep;
	t_cmd	*tmp;

	if ((cmd->exec_file_name[0] == '.' && cmd->exec_file_name[1] == '/')
		||cmd->exec_file_name[0]=='/')
		execve(cmd->exec_file_name, cmd->argv, NULL);
	str = ft_strdup(ft_getenv("PATH"));
	index = -1;
	sep = ft_p_split(str, ':'); // ft_split 과 동일
	parse_safe_free_multi_str(str, NULL, NULL, NULL);
	if (str == NULL || sep == NULL)
		return (-1);
	while (sep[++index])
	{
		str_tmp = ft_p_strjoin("/", cmd->exec_file_name);
		str = ft_p_strjoin(sep[index], str_tmp);
		printf("cmd = %s\n", str);
		// execve (str, cmd->argv, NULL);
		parse_safe_free_multi_str(str_tmp, str, NULL, NULL);
	}
	parse_safe_free_two_d_char(sep, -1);
	return (-1);
}

// 실행 전 syntax error 에 대한 식별이 필요함 cmd_list->status == TYPE_SYNTAX_ERR 라면 실행하면 안됨.
// 실행 전 cmd->string != NULL 에 대한 처리가 필요함 (거짓일 경우 check_exec_name_is_builtin를 실행시켜선 안됨)
int	check_exec_name_is_builtin(t_cmd *cmd)
{
	if (ft_p_strcmp(cmd->exec_file_name, "echo") == 0)
		return (ft_echo(cmd->argv, &(g_state.list)));
	else if (ft_p_strcmp(cmd->exec_file_name, "cd") == 0)
		return (ft_cd(cmd->argv, &(g_state.list)));
	else if (ft_p_strcmp(cmd->exec_file_name, "pwd") == 0)
		return (ft_pwd());
	else if (ft_p_strcmp(cmd->exec_file_name, "export") == 0)
		return (ft_export(cmd->argv, &(g_state.list)));
	else if (ft_p_strcmp(cmd->exec_file_name, "unset") == 0)
		return (ft_unset(cmd->argv, &(g_state.list)));
	else if (ft_p_strcmp(cmd->exec_file_name, "env")  == 0)
		return (ft_env(&(g_state.list)));
	else if (ft_p_strcmp(cmd->exec_file_name, "exit")  == 0)
		return (ft_exit(cmd->argv));
}