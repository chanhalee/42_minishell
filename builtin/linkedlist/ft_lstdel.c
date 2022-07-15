/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:50:41 by park              #+#    #+#             */
/*   Updated: 2022/07/16 01:47:45 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

int	ft_lstdelone(t_list *list, char *key)
{
    t_env *curr;

	curr = list->head->next;
    while (curr != list->tail)
    {
        if (ft_strcmp(curr->key, key) == 0)
        {
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr->key);
			free(curr->value);
			free(curr);
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}
