/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstviewall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:08:29 by park              #+#    #+#             */
/*   Updated: 2022/07/16 01:08:56 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void ft_viewall(t_list *list)
{
    t_env *seek;

	seek = list->head->next;
    while (seek != list->tail)
    {
        printf("key = %s, value = %s\n", seek->key, seek->value);
        seek = seek->next;
    }
}
