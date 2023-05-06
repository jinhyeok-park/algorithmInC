/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:06:10 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/26 16:08:19 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_len(char **strs, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_count_word(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	ft_sep_len(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

char	*ft_join(char **strs, char *result, char *sep, int size)
{
	int	i;
	int	k;
	int	stri;
	int	sepi;

	i = 0;
	k = 0;
	stri = 0;
	while (i < size)
	{
		k = 0;
		sepi = 0;
		while (strs[i][k])
			result[stri++] = strs[i][k++];
		while (sep[sepi] && i != size - 1)
			result[stri++] = sep[sepi++];
		i++;
	}
	result[stri] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len;
	int		i;
	int		temp;

	i = 0;
	if (!strs)
		return (0);
	if (size <= 0)
	{
		result = (char *)malloc(1);
		result[0] = 0;
		return (result);
	}
	len = ft_len(strs, size);
	temp = (size - 1) * ft_sep_len(sep);
	result = (char *)malloc(len + temp + 1);
	if (!result)
		return (0);
	return (ft_join(strs, result, sep, size));
}
