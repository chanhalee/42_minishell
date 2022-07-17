/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:38:43 by park              #+#    #+#             */
/*   Updated: 2022/07/17 15:22:29 by park             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "./linkedlist/linkedlist.h"
#include <unistd.h>
#include <stdio.h>

// cd .. : 상위 디렉토리로 이동합니다. 예를 들어 현재 위치가 /user/jtaewu라면 /user로 이동합니다.
// cd . : 현재 위치한 폴더로 이동합니다. 사실상 기능은 새로고침과 동일합니다.
// cd - : 이전에 위치했던 폴더로 이동합니다. 윈도우의 뒤로 가기와 동일합니다.
// cd / : ROOT 디렉토리로 이동합니다.
// cd ~ : 홈 디렉토리로 이동합니다.
// cd	: 홈 디렉토리로 이동합니다.

status_code ft_cd(char **argv, t_list *list)
{
	status_code	rst;
	char		*value;
	char		buff[1024];

	if (argv[1] == NULL || ft_strcmp(argv[1], "~") == 0)
	{
		value = ft_getenv(list, "HOME");
		if (value == NULL)
		{
			printf("bash: cd: HOME not set\n");
			return 0;
		}
	}
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		value = ft_getenv(list, "OLDPWD");
		if (value == NULL)
		{
			printf("bash: cd: OLDPWD not set\n");
			return 0;
		}
	}
	else
		value = argv[1];
	rst = chdir(value);
	if (rst == -1)
	{
		printf("bash: cd: %s: No such file or directory\n", argv[1]);
		return (rst);
	}
	else
	{
		getcwd(buff, 1024);
		ft_update_env(list, "OLDPWD", ft_getenv(list, "PWD"));
		ft_update_env(list, "PWD", buff);
	}
	// printf("OLDPWD = %s\n", ft_getenv(list, "OLDPWD"));
	// printf("PWD = %s\n", ft_getenv(list, "PWD"));
    return (rst);
}