/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:37:05 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/14 13:06:40 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	get_total_len(char **strs, char *sep, int size)
{
	int		i;
	int		k;
	int		total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
			k++;
		total_len += k;
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	total_len += i * (size - 1);
	return (total_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[k])
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*result;
	int		i;

	total_len = get_total_len(strs, sep, size);
	if (size <= 0)
	{
		result = (char *)malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	result = (char *)malloc(sizeof(char) * total_len + 1);
	i = 0;
	result[0] = '\0';
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i < size - 1)
			result = ft_strcat(result, sep);
		i++;
	}
	result[total_len] = '\0';
	return (result);
}
