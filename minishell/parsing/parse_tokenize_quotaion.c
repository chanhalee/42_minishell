/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize_quotaion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:00:00 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/13 20:50:50 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"
#include <stdio.h>

char	**seperate_quote(char *str);

void	tokenize_handle_quotaion(t_parse_token *tok_list)
{
	char			**sep;
	
	while (tok_list != NULL)
	{
		if (tok_list->token_type == TYPE_TOKEN_CHUNK)
		{
			sep = seperate_quote(tok_list->string);
			if (sep != NULL)
			{
				add_token(&tok_list, 1, TYPE_TOKEN_CHUNK, sep[2]);
				add_token(&tok_list, 1, TYPE_TOKEN_ARGV, sep[1]);
				free(tok_list->string);
				tok_list->string = ft_strdup(sep[0]);
				parse_safe_free_two_d_char(sep, -1);
				tok_list = tok_list->next;
			}
		}
		if (tok_list != NULL)
			tok_list = tok_list->next;
	}
}

char	**seperate_quote_sub_single_quote(char *str, int start, int end)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * 4);
	if (ret == NULL)
		return (NULL);
	ret[0] = ft_substr(str, 0, start);
	if (ret[0] == NULL)
		return (parse_safe_free_two_d_char(ret, -1));
	ret[1] = ft_substr(str, start + 1, end - start - 1);
	if (ret[1] == NULL)
		return (parse_safe_free_two_d_char(ret, -1));
	ret[2] = ft_substr(str, end + 1, ft_strlen(str));
	if (ret[2] == NULL)
		return (parse_safe_free_two_d_char(ret, -1));
	ret[3] = NULL;
	return (ret);
}

char	**seperate_quote_sub_double_quote(char *str, int start, int end)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * 4);
	if (ret == NULL)
		return (NULL);
	ret[0] = ft_substr(str, 0, start);
	if (ret[0] == NULL)
		return (parse_safe_free_two_d_char(ret, -1));
	ret[1] = ft_substr(str, start + 1, end - start - 1);
	ret[1] = parse_env_from_str(ret[1]);
	if (ret[1] == NULL)
		return (parse_safe_free_two_d_char(ret, -1));
	ret[2] = ft_substr(str, end + 1, ft_strlen(str));
	if (ret[2] == NULL)
		return (parse_safe_free_two_d_char(ret, -1));
	ret[3] = NULL;
	return (ret);
}

char	**seperate_quote(char *str)
{
	char	quotation;
	int		start;
	int		end;

	start = -1;
	while (str[++start] != '\0' && str[start] != '\'' && str[start] != '"')
	;
	if (str[start] == '\0')
		return (NULL);
	end = start;
	if (str[start] == '\'')
	{
		while (str[++end] != '\0' && str[end] != '\'')
		;
		if (str[end] == '\'')
			return (seperate_quote_sub_single_quote(str, start, end));
	}
	if (str[start] == '"')
	{
		while (str[++end] != '\0' && str[end] != '"')
		;
		if (str[end] == '"')
			return (seperate_quote_sub_double_quote(str, start, end));
	}
	return (NULL);
}