/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:39:21 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/15 16:25:59 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./do_not_submit.h"

void	print_token_list(t_parse_token *list)
{
	printf("\n=============tokens==============\n");
	printf("[");
	while (list != NULL)
	{
		printf(" {%s}(%d),", list->string, list->token_type);
		list = list->next;
	}
	printf("]\n");
}