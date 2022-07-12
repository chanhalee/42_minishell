/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_token_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:12:59 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/11 16:29:26 by chanhale         ###   ########.fr       */
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
