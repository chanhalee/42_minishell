/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize_merge_argv.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:30:13 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/17 12:04:41 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"

void	parse_tokenize_merge_argv(t_parse_token *tok_lst)
{
	t_parse_token	*tok;
	t_parse_token	*prev;
	char			*str;

	while (tok_lst != NULL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_ARGV && tok_lst->next
			&& tok_lst->next->token_type == TYPE_TOKEN_ARGV)
		{
			tok = tok_lst->next;
			str = ft_p_strjoin(tok_lst->string, tok->string);
			if (str == NULL)
				return ;
			tok_lst->next = tok_lst->next->next;
			free(tok_lst->string);
			tok_lst->string = str;
			free_single_t_parse_token(tok);
		}
		else
			tok_lst = tok_lst->next;
	}
}
