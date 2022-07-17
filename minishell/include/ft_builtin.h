/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:37:36 by park              #+#    #+#             */
/*   Updated: 2022/07/18 02:01:48 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

typedef int status_code;

# define PATH_MAX 1024
# define SUCCESS 1
# define FAIL 0

# include "ft_utils.h"
# include "linkedlist.h"
# include "command_parse.h"

int			find_env(char **env, char *key);
status_code ft_echo(char **argv, t_list *list);
status_code	ft_exit(char **argv);
status_code	ft_pwd(void);
status_code ft_cd(char **argv, t_list *list);
status_code	ft_unset(t_list *list, char **argv);

#endif