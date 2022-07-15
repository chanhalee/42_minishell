/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_syntex_err.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:17:55 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/15 18:27:53 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"

int	parse_check_syntex_err_set_err(t_parse_token *tok_lst, t_parse_token *err, t_parse_token *prev)
{
	char	*str;

	str = tok_lst->string;
	if (prev == NULL && (err->token_type == TYPE_TOKEN_PIPELINE))
	{
		tok_lst->token_type = TYPE_SYNTAX_ERR;
		tok_lst->string = err->string;
		err->string = str;
		return (0);
	}
	tok_lst->token_type = TYPE_SYNTAX_ERR;
	if (err->next == NULL)
	{
		str = ft_strdup("newline");
		if (str == NULL)
			return (0);
		free(tok_lst->string);
		tok_lst->string = str;
		return (0);
	}
	tok_lst->string = err->next->string;
	err->next->string = str;
	return (0);
}

int	parse_check_syntex_err(t_parse_token *tok_lst)
{
	t_parse_token	*tok;
	t_parse_token	*prev;
	char			*str;

	prev = NULL;
	tok = tok_lst;
	while (tok != NULL)
	{
		if (tok->token_type == TYPE_TOKEN_PIPELINE && (prev == NULL
			|| tok->next == NULL || prev->token_type != TYPE_TOKEN_ARGV))
			return (parse_check_syntex_err_set_err(tok_lst, tok, prev));
		if (tok->token_type >= TYPE_TOKEN_IO_R && tok->token_type <= TYPE_TOKEN_IO_LL
			&& (tok->next == NULL || tok->next->token_type != TYPE_TOKEN_ARGV))
			return (parse_check_syntex_err_set_err(tok_lst, tok, prev));
		prev = tok;
		tok = tok->next;
	}
	return (1);
}