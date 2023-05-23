/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_hardcode_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:20:25 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 21:47:54 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	four_data(t_list_ps *lista, int size)
{
	int	arr[4];
	int	i;

	arr[0] = lista->head->data;
	arr[1] = lista->head->next->data;
	arr[2] = lista->tail->data;
	arr[3] = lista->tail->prev->data;
	i = three_data(lista, size);
	if (size > 0 && arr[i] < arr[3])
		return (3);
	else if (size < 0 && arr[i] > arr[3])
		return (3);
	return (i);
}

int	three_data(t_list_ps *lista, int size)
{
	int	arr[3];

	arr[0] = lista->head->data;
	arr[1] = lista->head->next->data;
	arr[2] = lista->tail->data;
	if (size > 0 && arr[0] > arr[1] && arr[0] > arr[2])
		return (0);
	else if (size < 0 && arr[0] < arr[1] && arr[0] < arr[2])
		return (0);
	else if (size > 0 && arr[1] > arr[0] && arr[1] > arr[2])
		return (1);
	else if (size < 0 && arr[1] < arr[0] && arr[1] < arr[2])
		return (1);
	return (2);
}
