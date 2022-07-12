/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_token_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:12:59 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/12 23:31:23 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

void	free_t_parse_token_list(t_parse_token *token_list)
{
	t_parse_token	*next;
	
	next = token_list;
	while (next != NULL)
	{
		if (next->string != NULL)
			free (next->string);
		token_list = next;
		next = next->next;
		free (token_list);
	}
}

void	free_single_t_parse_token(t_parse_token *token_list)
{
	if (token_list == NULL)
	 	return ;
	if (token_list->string != NULL)
		free (token_list->string);
	free(token_list);
}