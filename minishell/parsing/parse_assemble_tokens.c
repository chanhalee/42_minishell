/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assemble_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:34:31 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/15 01:04:27 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"

t_parse_token	*parse_assemble_tokens_to_t_cmd_list(t_parse_token *tok_lst)
{
	t_cmd_list	*ret;
	t_cmd		*cmd;
	int			result;
	int			counter;

	ret = create_empty_t_cmd_list();
	if (ret == NULL)
		return (NULL);
	cmd = add_empty_t_cmd_to_list(ret);
	if (cmd == NULL)
		return (free_t_cmd_list);
	counter = -1;
	while (tok_lst != NULL && result != TYPE_FAIL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_PIPELINE)
		{
			cmd = add_empty_t_cmd_to_list(ret);
			if (cmd == NULL)
				return (free_t_cmd_list);
			counter = -1;
		}
		if (tok_lst->token_type == TYPE_TOKEN_ARGV)
			parse_t_cmd_add_argv(cmd, tok_lst->string, ++counter);
		if (tok_lst->token_type >= TYPE_TOKEN_IO_R
			&& tok_lst->token_type <= TYPE_TOKEN_IO_LL)
			add_cmd_redirection(cmd, tok_lst->token_type, tok_lst->next->string);
	}
}
