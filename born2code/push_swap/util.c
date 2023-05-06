/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:07:50 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/28 23:01:43 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1,"Error\n", 6);
}
//check it is interger , bigger than int duplicate 
int	string_checker(int ac, char **str)
{
	if (!isdigit_checker(ac, str) || !is_int(ac, str) \
	|| !duplicate_checker(ac, str))
		return (0);
	
	return (1);
}

long long long_changer(char *str)
{
	int	i;
	int	sign;
	long long ret;

	i = 0;
	ret = 0;
	sign = 1;
	if (str[i] == '-')
	{
		str++;
		sign = -1;
	}
	while (str[i])
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * sign);
}

int	is_int(int ac, char **str)
{
	int	i;
	long long temp;

	i = 1;
	while (i < ac)
	{
		temp = long_changer(str[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	*make_intarr(int ac, char **str)
{
	int	*ret;
	int	i;
	int	j;

	i = 1;
	j = 0;
	ret = (int *)malloc(sizeof(int) * (ac - 1));
	if (!ret)
		return (NULL);
	while (i < ac)
	{
		ret[j] = (int)long_changer(str[i]);
		i++;
		j++;
	}
	return (ret);
}

int check_self(int *num_arr, int c, int idx)
{
	int i;

	i = 0;
	while (i < idx)
	{
		if (num_arr[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	duplicate_checker(int ac, char **str)
{
	int	*ret;
	int	i;

	i = 0;
	ret = make_intarr(ac, str);
	if (!ret)
		return (0);
	while (i < ac - 1)
	{
		if (!check_self(ret, ret[i], i))
			return (0);
		i++;
	}
	return (1);
}

int	isdigit_checker(int ac, char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac <= 2)
		return (0);
	while (i < ac)
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}