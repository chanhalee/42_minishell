/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:32:33 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/15 16:17:19 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"
# include "./do_not_submit/do_not_submit.h"

t_cmd_list	*parse(char *raw_cmd_string)
{
	t_cmd_list		*ret;
	t_parse_token	*tokens;

	tokens = parse_tokenize(raw_cmd_string);
	if (tokens == NULL)
		return (NULL);
	if (tokens->token_type == TYPE_SYNTAX_ERR)
		return (handle_syntex_err_tok(tokens));
	ret = parse_assemble_tokens_to_t_cmd_list(tokens);
	free_t_parse_token_list(tokens);
	return (ret);
}