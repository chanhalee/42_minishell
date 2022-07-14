/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:24:36 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/13 14:16:45 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_parse.h"

size_t	ft_strlen(const char *s)
{
	size_t	iter;

	iter = 0;
	if (s == NULL)
		return (0);
	while (s[iter])
		iter++;
	return (iter);
}
