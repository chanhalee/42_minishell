/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_syntex_err_tok.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:03:59 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/16 15:54:41 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

t_cmd_list	*handle_syntex_err_tok(t_parse_token *tok_lst)
{
	char		*str;
	t_cmd_list	*ret;
	t_cmd		*cmd;

	if (tok_lst == NULL)
		str = ft_strdup("");
	else
		str = ft_strdup(tok_lst->string);
	free_t_parse_token_list(tok_lst);
	if (str == NULL)
		return (NULL);
	ret = create_empty_t_cmd_list();
	if (ret == NULL)
		return (parse_safe_free_multi_str(str, NULL, NULL, NULL));
	cmd = add_empty_t_cmd_to_list(ret);
	if (cmd == NULL)
	{
		free(str);
		return (free_t_cmd_list(ret));
	}
	ret->status = TYPE_SYNTAX_ERR;
	cmd->exec_file_name = str;
	return (ret);
}
