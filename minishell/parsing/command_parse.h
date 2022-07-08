/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:32:25 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/08 15:24:25 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_PARSE_H
# define COMMAND_PARSE_H

# include <unistd.h>
# include <stdlib.h>

# define TYPE_ERR_CODE_ALLOC 1
# define TYPE_INITIAL_STATUS 0


typedef	struct s_cmd
{
	char			*exec_file_path;
	char			**environment;
	char			**argv;
	char			**input_buffer;
	char			*output_buffer;
	struct s_cmd	*next;
}	t_cmd;

typedef	struct s_cmd_list
{
	struct s_cmd		*cmd_list;
	char				*first_cmd_input;
	int					status;
	struct s_cmd_list	*next_list;
}	t_cmd_list;

typedef	struct s_cmd_container
{
	struct s_cmd_list	*cmd_lists;
	int					status;
}	t_cmd_container;

t_cmd_container	*create_empty_cmd_container(void);
t_cmd_list		*add_empty_t_cmd_list(t_cmd_container *container);
t_cmd			*add_empty_t_cmd(t_cmd_list *cmd_list);
void			free_t_cmd_container(t_cmd_container *cmd_container);
t_cmd			*get_last_node(t_cmd *cmd_list);
t_cmd			*get_empty_t_cmd(void);

#endif