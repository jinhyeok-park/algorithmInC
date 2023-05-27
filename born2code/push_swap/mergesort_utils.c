/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:23:48 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/25 21:27:14 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_triangle(int depth, int size)
{
	int	*ret;
	int	i;
	int	arr_size;
	int	tri_size;

	tri_size = ft_pow(3, depth);
	ret = (int *)malloc(sizeof(int) * tri_size);
	if (!ret)
		exit(1);
	ret[0] = size;
	arr_size = 1;
	while (depth--)
	{
		i = -1;
		while (++i < arr_size)
		{
			tri_size = ret[i];
			ret[i] = tri_size / 3;
			ret[arr_size + i] = tri_size / 3 + tri_size % 3;
			ret[arr_size * 2 + i] = tri_size / 3;
		}
		arr_size *= 3;
	}
	return (ret);
}

int	get_order(int idx)
{
	int	flip;
	int	range;
	int	mirror;
	int	dist;

	flip = 0;
	while (idx > 0)
	{
		range = 0;
		while (idx / ft_pow(3, range))
			range++;
		mirror = ft_pow(3, range - 1);
		dist = idx - mirror;
		dist %= mirror;
		idx = mirror - dist - 1;
		flip++;
	}
	return (flip);
}

void	get_direction(int *sort_size, int dep)
{
	int	tri_size;
	int	i;
	int	temp;

	i = -1;
	tri_size = ft_pow(3, dep);
	while (++i < tri_size)
	{
		temp = get_order(i);
		if (temp % 2 == 1)
			sort_size[i] *= -1;
	}
}
