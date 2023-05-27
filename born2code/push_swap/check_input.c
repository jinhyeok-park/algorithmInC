/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:53:55 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/25 20:41:13 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int ac, char **av)
{
	long long	*new_av;
	int			len;

	if (!check_isdigit(ac, av))
		return (0);
	len = av_count(ac, av);
	new_av = make_new_av(ac, av);
	if (!check_dup(new_av, len) || !check_intmax(new_av, len))
	{
		free(new_av);
		return (0);
	}
	free(new_av);
	return (1);
}

int	check_intmax(long long *new_av, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (new_av[i] > 2147483647 || new_av[i] < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(long long *new_av, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!check_self(new_av, new_av[i], i))
			return (0);
		i++;
	}
	return (1);
}

long long	*make_new_av(int ac, char **av)
{
	int			i;
	int			j;
	int			k;
	long long	*ret;
	char		**temp;

	i = 0;
	k = 0;
	ret = (long long *)malloc(sizeof(long long) * av_count(ac, av));
	if (!ret)
		exit(1);
	while (++i < ac)
	{
		temp = ft_split(av[i], ' ');
		if (!temp)
			exit(1);
		j = -1;
		while (temp[++j])
			ret[k++] = ft_atoll(temp[j]);
		freeall(temp);
	}
	return (ret);
}

int	av_count(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) && av[i][j + 1] == ' ')
				count++;
			j++;
		}
		if (ft_isdigit(av[i][j - 1]) && av[i][j] == '\0')
			count++;
		i++;
	}
	return (count);
}
