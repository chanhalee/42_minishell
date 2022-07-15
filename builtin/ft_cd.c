/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: park <park@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:38:43 by park              #+#    #+#             */
/*   Updated: 2022/07/16 01:24:50 by park             ###   ########.fr       */
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

status_code ft_cd(char **argv, char **env)
{
	status_code	rst;

	rst = chdir(argv[1]);
	if (argv[1] == NULL)
		return (chdir());
	if (rst == -1)
	{
		printf("bash: cd: %s: No such file or directory\n", argv[1]);
		return -1;
	}
	printf("rst = %d\n", rst);
    return 1;
}