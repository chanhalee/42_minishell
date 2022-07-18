/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:24 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/17 12:04:41 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"

void			parse_env_from_tok_sub(t_parse_token *tok);
char			*parse_env_from_str_sub(char *str, int end);
void			parse_env_from_tok(t_parse_token *tok);

void	parse_env_from_token_list(t_parse_token *tok_lst)
{
	t_parse_token	*next;

	while (tok_lst != NULL)
	{
		next = tok_lst->next;
		if (tok_lst->token_type == TYPE_TOKEN_CHUNK)
			parse_env_from_tok(tok_lst);
		tok_lst = next;
	}
}

void	parse_env_from_tok(t_parse_token *tok)
{
	char			**split_str;
	t_parse_token	*next;
	int				index;

	split_str = ft_p_split_custom(tok->string, '$');
	if (split_str == NULL)
		return ;
	free (tok->string);
	tok->string = ft_p_strdup(split_str[0]);
	index = 0;
	while (split_str[++index] != NULL)
		add_token(&tok, index, tok->token_type, split_str[index]);
	parse_safe_free_two_d_char(split_str, -1);
	while (--index >= 0 && tok != NULL)
	{
		next = tok->next;
		if (tok->string[0] == '$' && (tok->string[1] == '_'
				|| (tok->string[1] >= 'A' && tok->string[1] <= 'Z')
				|| (tok->string[1] >= 'a' && tok->string[1] <= 'z')))
			parse_env_from_tok_sub(tok);
		tok = next;
	}
}

void	parse_env_from_tok_sub(t_parse_token *tok)
{
	int		end;
	char	*str;
	char	*str2;
	char	*str3;

	end = 1;
	str = tok->string;
	while (str[end] == '_' || (str[end] >= 'A' && str[end] <= 'Z') || (str[end]
			>= 'a' && str[end] <= 'z') || (str[end] >= '0' && str[end] <= '9'))
		end++;
	str2 = ft_p_substr(str, 1, end - 1);
	if (str2 == NULL)
		return ;
	str3 = ft_getenv(str2);
	free(str2);
	if (str3 == NULL)
		str3 = "";
	str3 = ft_strdup(str3);
	if (str3 == NULL)
		return ;
	tok->string = str3;
	str3 = ft_p_substr(str, end, ft_p_strlen(str));
	add_token(&tok, 1, tok->token_type, str3);
	parse_safe_free_multi_str(str, str3, NULL, NULL);
	tok->token_type = TYPE_TOKEN_ARGV;
	if (tok->string[0] != '\0')
		parse_tokenize_space_single_tok(tok);
}

char	*parse_env_from_str(char *str)
{
	char	**split_str;
	char	*ret;
	char	*str_tmp;
	char	*str_tmp2;
	int		index;

	split_str = ft_p_split_custom(str, '$');
	if (split_str == NULL)
		return (str);
	index = -1;
	ret = ft_p_strdup("");
	while (split_str[++index] != NULL && ret != NULL)
	{
		str_tmp2 = ft_p_strdup(split_str[index]);
		if (str_tmp2[0] == '$')
			str_tmp2 = parse_env_from_str_sub(str_tmp2, 0);
		str_tmp = ret;
		ret = ft_p_strjoin(ret, str_tmp2);
		parse_safe_free_multi_str(str_tmp, str_tmp2, NULL, NULL);
	}
	parse_safe_free_two_d_char(split_str, -1);
	if (ret == NULL)
		return (str);
	free(str);
	return (ret);
}

char	*parse_env_from_str_sub(char *str, int end)
{
	char	*str1;
	char	*str2;
	char	*str3;

	if (str[++end] != '_' && !(str[end] >= 'A' && str[end] <= 'Z')
		&& !(str[end] >= 'a' && str[end] <= 'z'))
		return (str);
	while (str[end] == '_' || (str[end] >= 'A' && str[end] <= 'Z') || (str[end]
			>= 'a' && str[end] <= 'z') || (str[end] >= '0' && str[end] <= '9'))
		end++;
	str2 = ft_p_substr(str, 1, end - 1);
	if (str2 == NULL)
		return (str);
	str3 = ft_getenv(str2);
	free(str2);
	if (str3 == NULL)
		str3 = "";
	str2 = ft_substr(str, end, ft_strlen(str));
	str3 = ft_strjoin(str3, str2);
	parse_safe_free_multi_str(str2, NULL, NULL, NULL);
	if (str1 == NULL)
		return (str);
	free (str);
	return (str3);
}
