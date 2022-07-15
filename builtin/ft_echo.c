/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:37:43 by park              #+#    #+#             */
/*   Updated: 2022/07/15 19:35:01 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include <stdio.h>


status_code ft_echo(char **argv)
{
    int newline;
    int idx;

    newline = 0;
    idx = 1;
    if (ft_strncmp(argv[1], "-n", 2) == 0)
    {
        idx = 2;
        newline = 1;
    }
    while (argv[idx] != NULL)
    {
        printf("%s", argv[idx]);
        if (argv[idx + 1] != NULL)
            printf(" ");
        idx++;
    }
    if (newline == 0)
        printf("\n");
    return 1;
}

