/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:21:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/03 14:09:00jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list_ps	*list;
	int			len;

	len = av_count(ac, av);
	if (ac < 2 || len < 2)
		return (0);
	if (!check_input(ac, av))
	{
		error_msg();
		return (0);
	}
	list = make_list(ac, av, len);
	if (!list)
		return (0);
	if(issorting(list))
		exit(0);
	sorting(list);
	// while (list->size--)
	// {
	// 	printf("%d " , list->head->data);
	// 	list->head = list->head->next;
	// }
}