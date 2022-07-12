/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:49:36 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/13 00:41:07 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"
#include <stdio.h>

void	tokenize_annihilate_empty_chunk(t_parse_token **tok_lst);

t_parse_token	*parse_tokenize(char *cmd_string)
{
	t_parse_token	*ret;
	ret = create_empty_t_parse_token();
	if (ret == NULL)
		return (NULL);
	ret->token_type = TYPE_TOKEN_CHUNK;
	ret->string = cmd_string;
	tokenize_handle_quotaion(ret);
	parse_env_from_token_list(ret);
	parse_tokenize_space(ret);

	return (ret);
}

void	tokenize_annihilate_empty_chunk(t_parse_token **tok_lst)
{
	t_parse_token	*tok;
	t_parse_token	*prev;

	if (tok_lst == NULL || *tok_lst == NULL)
		return;
	tok = (*tok_lst);
	while ((*tok_lst)->next != NULL && (*tok_lst)->token_type == TYPE_TOKEN_CHUNK
		&& (*(*tok_lst)->string) == '\0')
	{
		tok = (*tok_lst);
		(*tok_lst) = tok->next;
		free_single_t_parse_token(tok);
	}
	prev = (*tok_lst);
	while (prev->next != NULL)
	{
		tok = prev->next;
		if (tok->token_type == TYPE_TOKEN_CHUNK && *(tok->string) == '\0')
		{
			prev->next = tok->next;
			free (tok);
		}
		prev = prev->next;
	}
}
