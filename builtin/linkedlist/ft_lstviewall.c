/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstviewall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:08:29 by park              #+#    #+#             */
/*   Updated: 2022/07/16 15:07:34 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>

void ft_viewall(t_list *list)
{
    t_env *curr;

	curr = list->head->next;
    while (curr != list->tail)
    {
        printf("%s=%s\n", curr->key, curr->value);
        curr = curr->next;
    }
}
