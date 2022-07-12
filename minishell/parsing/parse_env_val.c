/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:04:24 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/12 19:43:45 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./command_parse.h"

char	*parse_env_from_str_sub(char *str);

char	*parse_env_from_str(char *str)
{
	char	**split_str;
	char	*ret;
	char	*str_tmp;
	char	*str_tmp2;
	int		index;

	split_str = ft_split_custom(str, '$');
	if (split_str == NULL)
		return(str);
	index = -1;
	ret = ft_strdup("");
	while (split_str[++index] != NULL && ret != NULL)
	{
		str_tmp2 = ft_strdup(split_str[index]);
		str_tmp2 = parse_env_from_str_sub(str_tmp2);
		str_tmp = ret;
		ret = ft_strjoin(ret, str_tmp2);
		parse_err_free_multi_str(str_tmp, str_tmp2, NULL, NULL);
	}
	parse_err_free_two_d_char(split_str);
	if (ret == NULL)
		return (str);
	free(str);
	return (ret);
}

char	*parse_env_from_str_sub(char *str)
{
	int		start;
	int		end;
	char	*str1;
	char	*str2;
	char	*str3;
	
	start = -1;
	if (str == NULL)
		return (str);
	while (str[++start] != '\0' && str[start] != '$')
		;
	if (str[start] == '\0')
		return (str);
	end = start;
	if (str[++end] != '_' && !(str[end] >= 'A' && str[end] <= 'Z')
		&& !(str[end] >= 'a' && str[end] <= 'z'))
		return (str);
	while (str[++end] == '_' || (str[end] >= 'A' && str[end] <= 'Z')
		|| (str[end] >= 'a' && str[end] <= 'z') || (str[end] >= '0' && str[end] <= '9'))
		;
	str1 = ft_substr(str, 0, start);
	if (str1 == NULL)
		return (str);
	str2 = ft_substr(str, start + 1, end - start - 1);
	if (str2 == NULL)
	{
		free(str1);
		return (str);
	}
	str3 = getenv(str2);
	free(str2);
	if (str3 == NULL)
		str3 = ft_strdup("");
	str2 = ft_strjoin(str1, str3);
	parse_err_free_multi_str(str1, NULL, NULL, NULL);
	str3 = ft_substr(str, end, ft_strlen(str));
	if (str3 == NULL)
	{
		free(str2);
		return (str);
	}
	str1 = ft_strjoin(str2, str3);
	parse_err_free_multi_str(str2, str3, NULL, NULL);
	if (str1 == NULL)
		return (str);
	free (str);
	return (str1);
}