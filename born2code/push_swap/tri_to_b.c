/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_to_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:38:06 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/25 19:44:11 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tob(t_list_ps *lista, t_list_ps *listb, int *sort_size, int dep)
{
	int	tri;
	int	temp;
	int	i;

	tri = ft_pow(3, dep - 1);
	i = ft_pow(3, dep);
	i--;
	while (tri--)
	{
		temp = ft_abs(sort_size[i--]);
		while (temp--)
			pb(lista, listb, 1);
	}
	make_tri_a(lista, listb, i, dep);
}

void	make_tri_a(t_list_ps *lista, t_list_ps *listb, int idx, int dep)
{
	int	mirror;
	int	arr[3];
	int	*sort_size;
	int	i;

	sort_size = get_triangle(dep, lista->size + listb->size);
	get_direction(sort_size, dep);
	mirror = ft_pow(3, dep - 1);
	i = 0;
	while (mirror)
	{
		arr[0] = (sort_size[idx - i]);
		arr[1] = (sort_size[idx + mirror]);
		arr[2] = (sort_size[idx - (2 * mirror - 1 + i++)]);
		make_tri2_a(lista, listb, arr);
		mirror--;
	}
	free(sort_size);
}

void	make_tri2_a(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	int	sign;

	if (arr[0] < 0 && arr[1] < 0 && arr[2] > 0)
		sign = 1;
	else
		sign = -1;
	if (sign == 1)
		make_tri_up_a(lista, listb, arr);
	else
		make_tri_down_a(lista, listb, arr);
}

void	make_tri_down_a(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	int	count;

	count = 0;
	make_posit(arr);
	while (1)
	{
		check_all_ad(lista, listb, arr);
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break ;
		count++;
	}
	if (issorting(listb) && lista->size == 0)
		last_to_a(lista, listb);
}

void	make_tri_up_a(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	int	count;

	count = 0;
	make_posit(arr);
	while (1)
	{
		check_all_a(lista, listb, arr);
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break ;
		count++;
	}
	if (issorting(listb) && lista->size == 0)
		last_to_a(lista, listb);
}
