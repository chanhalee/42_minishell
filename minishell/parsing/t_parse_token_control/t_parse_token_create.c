/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_token_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:53:03 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/11 17:28:43 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

t_parse_token	*create_empty_t_parse_token(void)
{
	t_parse_token	*ret;

	ret = (t_parse_token *)malloc(sizeof(t_parse_token));
	if (ret == NULL)
		return (NULL);
	ret->next = NULL;
	ret->string = NULL;
	ret->token_type = 0;
	return (ret);
}

t_parse_token	*add_t_parse_token_to_list(t_parse_token **token_list,
		size_t index, int type, char *content)
{
	t_parse_token	*ret;
	t_parse_token	*prev;

	if (token_list == NULL)
		return (NULL);
	ret = (t_parse_token *)malloc(sizeof(t_parse_token));
	if (ret == NULL)
		return (NULL);
	ret->token_type = type;
	ret->string = content;
	if (*token_list == NULL || index == 0)
	{
		ret->next = (*token_list);
		(*token_list) = ret;
		return (ret);
	}
	prev = (*token_list);
	while (prev->next != NULL && --index > 0)
		prev = prev->next;
	ret->next = prev->next;
	prev->next = ret;
	return (ret);
}