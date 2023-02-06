/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:54:59 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/28 10:57:06 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_check(char str_c, char *charset)
{
	int	i;

	i = 0;
	if (str_c == '\0')
		return (0);
	while (charset[i])
	{
		if (charset[i] == str_c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (ft_check(str[i], charset) && !ft_check(str[i + 1], charset))
			result++;
		i++;
	}
	return (result);
}

void	ft_putchar(char *result, char *str, char *charset)
{
	int	i;

	i = 0;
	while (ft_check(str[i], charset))
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
}

void	ft_setword(char **result, char *str, char *charset)
{
	int	i;
	int	result_index;
	int	word_len;

	i = 0;
	result_index = 0;
	while (str[i])
	{
		if (!ft_check(str[i], charset))
			i++;
		else
		{
			word_len = 0;
			while (ft_check(str[i + word_len], charset))
				word_len++;
			result[result_index] = (char *)malloc(sizeof(char) * word_len + 1);
			if (!result[result_index])
				return ;
			ft_putchar(result[result_index], str + i, charset);
			i += word_len;
			result_index++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		word_cnt;
	char	**result;

	word_cnt = ft_count_word(str, charset);
	result = (char **)malloc(sizeof(char *) * word_cnt + 1);
	if (!result)
		return (0);
	ft_setword(result, str, charset);
	result[word_cnt] = 0;
	return (result);
}
