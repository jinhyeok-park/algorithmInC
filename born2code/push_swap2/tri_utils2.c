/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:36:14 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:37:06 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int abs)
{
	if (abs < 0)
	{
		abs *= -1;
		return (abs);
	}
	return (abs);
}

int	find_max_intri_a(t_list_ps *lista, t_list_ps *listb)
{
	int	num[3];
	int	i;
	int	ret;

	num[0] = lista->head->data;
	num[1] = listb->tail->data;
	num[2] = lista->tail->data;
	i = 3;
	ret = num[0];
	while (i--)
	{
		if (ret < num[i])
			ret = num[i];
	}
	if (num[0] == ret)
		return (0);
	else if (num[1] == ret)
		return (1);
	return (2);
}

int	find_max_intri(t_list_ps *lista, t_list_ps *listb)
{
	int	num[3];
	int	i;
	int	ret;

	num[0] = listb->head->data;
	num[1] = lista->tail->data;
	num[2] = listb->tail->data;
	i = 3;
	ret = num[0];
	while (i--)
	{
		if (ret < num[i])
			ret = num[i];
	}
	if (num[0] == ret)
		return (0);
	else if (num[1] == ret)
		return (1);
	return (2);
}

int	find_min_tri(t_list_ps *lista, t_list_ps *listb)
{
	int	num[3];
	int	i;
	int	ret;

	num[0] = listb->head->data;
	num[1] = lista->tail->data;
	num[2] = listb->tail->data;
	i = 3;
	ret = num[0];
	while (i--)
	{
		if (ret > num[i])
			ret = num[i];
	}
	if (num[0] == ret)
		return (0);
	else if (num[1] == ret)
		return (1);
	return (2);
}

int	find_min_tri_d(t_list_ps *lista, t_list_ps *listb)
{
	int	num[3];
	int	i;
	int	ret;

	num[0] = lista->head->data;
	num[1] = listb->tail->data;
	num[2] = lista->tail->data;
	i = 3;
	ret = num[0];
	while (i--)
	{
		if (ret > num[i])
			ret = num[i];
	}
	if (num[0] == ret)
		return (0);
	else if (num[1] == ret)
		return (1);
	return (2);
}
