/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:36:31 by park              #+#    #+#             */
/*   Updated: 2022/07/18 02:06:05 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linkedlist.h"

void	ft_lstadd(t_list *list, char *key, char *value)
{
    t_env *curr = ft_lstnew(key, value);
    curr->prev = list->tail->prev;
    curr->next = list->tail;
    list->tail->prev->next = curr;
    list->tail->prev = curr;
}