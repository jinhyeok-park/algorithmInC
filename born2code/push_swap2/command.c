/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:23:33 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:07:52 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list_ps *list, int flag)
{
	int	temp;

	if (list)
	{
		if (list->head && list->tail)
		{
			temp = list->head->data;
			pop_head(list);
			push_tail(list, temp);
			if (flag)
				write(1, "ra\n", 3);
			return (1);
		}
	}
	return (0);
}

int	rb(t_list_ps *list, int flag)
{
	int	temp;

	if (list)
	{
		if (list->head && list->tail)
		{
			temp = list->head->data;
			pop_head(list);
			push_tail(list, temp);
			if (flag)
				write(1, "rb\n", 3);
			return (1);
		}
	}
	return (0);
}

int	rra(t_list_ps *list, int flag)
{
	int	temp;

	if (list)
	{
		if (list->head && list->tail)
		{
			temp = list->tail->data;
			pop_tail(list);
			push_head(list, temp);
			if (flag)
				write(1, "rra\n", 4);
			return (1);
		}
	}
	return (0);
}

int	rrb(t_list_ps *list, int flag)
{
	int	temp;

	if (list)
	{
		if (list->head && list->tail)
		{
			temp = list->tail->data;
			pop_tail(list);
			push_head(list, temp);
			if (flag)
				write(1, "rrb\n", 4);
			return (1);
		}
	}
	return (0);
}
