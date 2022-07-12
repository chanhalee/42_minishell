/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:55:34 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/11 16:24:48 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../command_parse.h"

t_cmd	*get_empty_t_cmd(void) // if worng_return_null
{
	t_cmd	*ret;

	ret = (t_cmd *)malloc(sizeof(t_cmd));
	if (ret == NULL)
		return (NULL);
	ret->exec_file_path = NULL;
	ret->environment = NULL;
	ret->argv = NULL;
	ret->input_buffer = NULL;
	ret->output_buffer = NULL;
	ret->next = NULL;
	ret->redirection_list = NULL;
	return (ret);
}

t_cmd	*add_empty_t_cmd(t_cmd_list *cmd_list)
{
	t_cmd	*new_node;
	t_cmd	*prev_node;

	if (cmd_list == NULL)
		return (NULL);
	new_node = get_empty_t_cmd();
	if (new_node == NULL)
		return (NULL);
	if (cmd_list->cmd_list == NULL)
	{
		cmd_list->cmd_list = new_node;
		new_node->input_buffer = &(cmd_list->first_cmd_input);
		return (new_node);
	}
	prev_node = cmd_list->cmd_list;
	while (prev_node -> next != NULL)
		prev_node = prev_node->next;
	prev_node->next = new_node;
	new_node->input_buffer = &(prev_node->output_buffer);
	return (new_node);
}

t_cmd_list	*create_empty_t_cmd_list(void)
{
	t_cmd_list	*ret;
	t_cmd_list	*prev_list;

	ret = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	if (ret == NULL)
		return (NULL);
	ret->cmd_list = NULL;
	ret->status = TYPE_INITIAL_STATUS;
	ret->first_cmd_input = NULL;
	ret->next_list = NULL;
	return (ret);
}

t_cmd_redirection	*add_empty_cmd_redirection(t_cmd *cmd, int red_type, char *file)
{
	t_cmd_redirection	*ret;
	t_cmd_redirection	*prev;

	ret = (t_cmd_redirection *)malloc(sizeof(t_cmd_redirection));
	if (ret == NULL)
		return (NULL);
	ret->red_type = red_type;
	ret->file = file;
	ret->next = NULL;
	if (cmd->redirection_list == NULL)
		cmd->redirection_list = ret;
	else
	{
		prev = cmd->redirection_list;
		while (prev->next != NULL)
			prev = prev->next;
		prev->next = ret;
	}
	return (ret);
}
