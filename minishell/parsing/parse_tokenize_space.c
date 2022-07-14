/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:24:47 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/13 20:50:49 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"
#include <stdio.h>

void	parse_tokenize_space_sep(t_parse_token *tok_lst);

void	parse_tokenize_space(t_parse_token *tok_lst)
{
	t_parse_token	*next_tok;
	t_parse_token	*preserve;
	char			**sep;
	int				index;
	
	preserve = tok_lst;
	while (tok_lst != NULL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_CHUNK)
		{
			sep = ft_split_custom(tok_lst->string, ' ');
			index = 0;
			if (sep == NULL || sep[0] == NULL)
				return;
			free(tok_lst->string);
			tok_lst->string = ft_strdup(sep[0]);
			next_tok = tok_lst;
			while (sep[++index] != NULL && next_tok != NULL)
				next_tok = add_token(&tok_lst, index, TYPE_TOKEN_CHUNK, sep[index]);
			parse_safe_free_two_d_char(sep, -1);
			tok_lst = next_tok;
		}
		if (tok_lst == NULL)
			break ;
		tok_lst = tok_lst->next;
	}
	parse_tokenize_space_sep(preserve);
}

void	parse_tokenize_space_single_tok(t_parse_token *tok)
{
	char			**sep;
	int				type;
	int				index;

	sep = ft_strsep_custom(tok->string, ' ');
	index = -1;
	if (sep == NULL || sep[0] == NULL)
		return;
	type = tok->token_type;
	cleanse_single_t_parse_token(tok);
	while (sep[++index] != NULL && tok != NULL)
	{
		if (sep[index][0] == ' ')
		{
			if (add_token(&tok, 1, TYPE_TOKEN_SPACE, sep[index]))
				tok = tok->next;
		}
		else
		{
			if (add_token(&tok, 1, type, sep[index]))
				tok = tok->next;
		}
	}
	parse_safe_free_two_d_char(sep, -1);
}

void	parse_tokenize_space_sep(t_parse_token *tok_lst)
{
	t_parse_token	*tok;

	while (tok_lst != NULL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_CHUNK && *(tok_lst->string) == ' ')
		{
			tok = add_token(&tok_lst, 1, TYPE_TOKEN_CHUNK, (tok_lst->string) + 1);
			if (tok == NULL)
				return ;
			free(tok_lst->string);
			tok_lst->token_type = TYPE_TOKEN_SPACE;
			tok_lst->string = ft_strdup(" ");
			tok_lst = tok;
		}
		tok_lst = tok_lst->next;
	}
}