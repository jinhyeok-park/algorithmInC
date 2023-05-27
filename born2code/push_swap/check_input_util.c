/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:17:41 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/26 15:05:45 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_self(long long *new_av, long long cur, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (new_av[i] == cur)
			return (0);
		i++;
	}
	return (1);
}

int	check_isdigit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
				return (0);
			if (av[i][j] == '-')
			{
				if (!ft_isdigit(av[i][j + 1]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	freeall(char **s)
{
	int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			free(s[i]);
		free(s);
	}
}

int	sp_nu_checker(int ac, char **av)
{
	int	i;
	int	flag;
	int	j;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == 0)
			return (0);
		j = -1;
		flag = 0;
		while (av[i][++j])
		{
			if (av[i][j] != 32)
				flag = 1;
			if (flag)
				break ;
		}
		if (flag == 0)
			return (0);
	}
	return (1);
}
