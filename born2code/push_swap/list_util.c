/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:35:15 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/25 21:20:21 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*create_list(void)
{
	t_list_ps	*list;

	list = (t_list_ps *)malloc(sizeof(t_list_ps));
	if (!list)
		exit (1);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

void	free_list(t_list_ps *list)
{
	t_node	*throw;

	while (list->size--)
	{
		throw = list->head;
		list->head = list->head->next;
		free(throw);
	}
	free(list);
}
