/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:32:33 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/10 16:09:40 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"
#include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

int	main(int argc, char **argv)
{
	char	*buff;
	readline(buff);
	printf("%s\n", buff);
	printf("1%s\n", buff);
	printf("1%s\n", buff);
	free(buff);
	system("leaks test");
	return (0);
}