/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroh <sroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:04:29 by sroh              #+#    #+#             */
/*   Updated: 2023/02/01 18:26:32 by sroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_check_num(char *file)
{
	int	i;
	int	j;
	int	num;
	int	result;

	i = 1;
	j = 0;
	result = 0;
	while (file[i] != '\n')
		i++;
	if (j >= i - 3)
		return (-1);
	while (j < i - 3)
	{
		if (file[j] < '0' || file[j] > '9')
			return (-1);
		num = file[j] - 48;
		result *= 10;
		result += num;
		j++;
	}
	return (result);
}

char	*ft_make_charset(char *file)
{
	int		i;
	int		j;
	char	*charset;
	int		idx;

	i = 1;
	while (file[i] != '\n')
		i++;
	charset = (char *)malloc(4);
	if (!charset)
	{
		free(charset);
		return (0);
	}
	j = i - 3;
	idx = 0;
	while (file[j] != '\n')
	{
		charset[idx] = file[j];
		j++;
		idx++;
	}
	charset[idx] = '\0';
	return (charset);
}

int	ft_check_input(char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (charset[i])
	{
		if (charset[i] < 32 || charset[i] == 127)
			return (0);
		while (j < i)
		{
			if (charset[j] == charset[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
