/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 00:49:43 by park              #+#    #+#             */
/*   Updated: 2022/07/16 01:12:35 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void ft_initlist(t_list *list)
{
    list->head = ft_lstnew("", "");
    list->tail = ft_lstnew("", "");
    list->head->next = list->tail;
    list->tail->prev = list->head;
}