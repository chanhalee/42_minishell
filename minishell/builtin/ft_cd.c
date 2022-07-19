/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:38:43 by park              #+#    #+#             */
/*   Updated: 2022/07/19 14:59:39 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include "../include/linkedlist.h"
#include <unistd.h>
#include <stdio.h>

// cd .. : 상위 디렉토리로 이동합니다. 예를 들어 현재 위치가 /user/jtaewu라면 /user로 이동합니다.
// cd . : 현재 위치한 폴더로 이동합니다. 사실상 기능은 새로고침과 동일합니다.
// cd - : 이전에 위치했던 폴더로 이동합니다. 윈도우의 뒤로 가기와 동일합니다.
// cd / : ROOT 디렉토리로 이동합니다.
// cd ~ : 홈 디렉토리로 이동합니다.
// cd	: 홈 디렉토리로 이동합니다.

int	ft_cd(char **argv, t_list *list)
{
	int		rst;
	char	*value;
	char	buff[9999];

	if (argv[1] == NULL || ft_strcmp(argv[1], "~") == 0)
	{
		value = ft_getenv("HOME");
		if (value == NULL)
		{
			printf("bash: cd: HOME not set\n");
			return (1);
		}
	}
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		value = ft_getenv("OLDPWD");
		if (value == NULL)
		{
			printf("bash: cd: OLDPWD not set\n");
			return (1);
		}
	}
	else
		value = argv[1];
	rst = chdir(value);
	if (rst == -1)
	{
		printf("bash: cd: %s: No such file or directory\n", argv[1]);
		return (1);
	}
	else
	{
		getcwd(buff, 9999);
		ft_update_env(list, "OLDPWD", ft_getenv("PWD"));
		ft_update_env(list, "PWD", buff); 
	}
	return (0);
}