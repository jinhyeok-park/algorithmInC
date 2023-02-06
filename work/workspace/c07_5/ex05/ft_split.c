/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:56:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/26 16:16:30 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check(char ch, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (ch == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i + 1])
	{
		if (ft_check(str[i], charset) \
				&& !ft_check(str[i + 1], charset))
			count++;
		i++;
	}
	if (ft_check(str[i], charset) && str[i + 1] == 0)
		count++;
	return (count);
}

char	*ft_wordlen(char *str, char *charset, int *len)
{
	int	i;

	i = 0;
	while (ft_check(str[i], charset))
		i++;
	*len = i;
	return (str + i);
}

void	ft_result(char **result, char *str, char *charset, int *len)
{
	int		i;
	int		k;
	char	*temp;

	k = 0;
	temp = str;
	while (k < ft_count_word(str, charset))
	{
		while (!ft_check(*temp, charset))
			temp++;
		temp = ft_wordlen(temp, charset, len);
		result[k] = (char *)malloc(*len + 1);
		i = 0;
		while (i < *len)
		{
			result[k][i] = temp[i - *len];
			i++;
		}
		result[k][i] = 0;
		k++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		wordlen;
	char	**result;

	wordlen = 0;
	result = (char **)malloc(sizeof(char *) * \
			(ft_count_word(str, charset) + 1));
	result[ft_count_word(str, charset)] = 0;
	if (!result)
		return (0);
	if (!*str || !ft_count_word(str, charset))
	{
		result[0] = 0;
		return (result);
	}
	if (ft_count_word(str, charset) == 1 && !(*charset))
	{
		*result = str;
		result++;
		*result = 0;
		return (--result);
	}
	ft_result(result, str, charset, &wordlen);
	return (result);
}

int main(int ac, char **av)
{
	(void)ac;
	char **result;
	result = ft_split(av[1], av[2]);
	for (int i = 0 ; result[i]; i++)
	{
		printf("%s" , result[i]);
	}
}
