/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:37:36 by park              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/19 16:36:15 by chanhale         ###   ########.fr       */
=======
/*   Updated: 2022/07/19 15:31:48 by jeounpar         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# define PATH_MAX 1024
# define SUCCESS 1
# define FAIL 0

# include "ft_utils.h"
# include "linkedlist.h"
# include "command_parse.h"

int		find_env(char **env, char *key);
int		ft_echo(char **argv, t_list *list);
int		ft_pwd(void);
int		ft_env(t_list *list);
int		ft_cd(char **argv, t_list *list);
int		ft_unset(char **argv, t_list *list);
int		ft_export(char **argv, t_list *list);
int		ft_exit(char **argv);
int		ft_exec(t_cmd_list *lists);

#endif