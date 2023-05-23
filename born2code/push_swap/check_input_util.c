/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:17:41 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:31:02 by jinhyeok         ###   ########.fr       */
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
