/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:26:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/25 19:42:33 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(t_list_ps *lista, t_list_ps *listb)
{
	int	dep;
	int	*sort_size;

	dep = depth(lista->size + listb->size);
	sort_size = get_triangle(dep, lista->size + listb->size);
	get_direction(sort_size, dep);
	to_b(lista, listb, sort_size, dep);
	free(sort_size);
	sort_all(lista, listb, dep);
}

void	to_b(t_list_ps *lista, t_list_ps *listb, int *sort_size, int dep)
{
	int	i;
	int	size;

	i = -1;
	size = ft_pow(3, dep);
	while (++i < size)
	{
		if (sort_size[i] == 5 || sort_size[i] == -5)
			merge_5(lista, listb, sort_size[i]);
		else if (sort_size[i] == 4 || sort_size[i] == -4)
			merge_4(lista, listb, sort_size[i]);
		else if (sort_size[i] == 3 || sort_size[i] == -3)
			merge_3(lista, listb, sort_size[i]);
		else if (sort_size[i] == 2 || sort_size[i] == -2)
			merge_2(lista, listb, sort_size[i]);
		else
			pb(lista, listb, 1);
	}
}

void	sort_all(t_list_ps *lista, t_list_ps *listb, int dep)
{
	int	*sort_size;

	while (dep)
	{
		sort_size = get_triangle(dep, lista->size + listb->size);
		get_direction(sort_size, dep);
		if (listb->size == 0)
			tob(lista, listb, sort_size, dep);
		else
			to_a(lista, listb, sort_size, dep);
		free(sort_size);
		dep--;
	}
}
