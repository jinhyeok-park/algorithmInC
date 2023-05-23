/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:22:37 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:02:35 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list_ps *lista, t_list_ps *listb)
{
	int	minimum;
	int	num[3];
	int	i;
	int	ret;

	num[0] = lista->head->data;
	num[1] = lista->head->next->data;
	num[2] = lista->tail->data;
	minimum = listb->head->data;
	i = 3;
	ret = 0;
	while (i--)
	{
		if (ret < num[i] && num[i] < minimum)
			ret = num[i];
	}
	if (num[0] == ret)
		return (0);
	else if (num[1] == ret)
		return (1);
	return (2);
}

int	issorting(t_list_ps *list)
{
	int		i;
	t_node	*temp;

	temp = list->head;
	i = 0;
	while (++i < list->size)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_pow(int num, int power)
{
	int	ret;

	ret = 1;
	if (0 == power)
		return (1);
	if (num == 0)
		return (0);
	while (power--)
		ret *= num;
	return (ret);
}

int	depth(int size)
{
	int	depth;

	depth = 0;
	while (size)
	{
		if (size < 5)
			break ;
		size = size / 3 + size % 3;
		depth++;
	}
	return (depth);
}

void	make_posit(int *arr)
{
	int	i;

	i = -1;
	while (++i < 3)
		arr[i] = ft_abs(arr[i]);
}
