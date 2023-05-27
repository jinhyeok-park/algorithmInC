/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:38:54 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/25 21:37:11 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*make_list(int ac, char **av, int len)
{
	long long	*new_av;
	t_list_ps	*list;

	new_av = make_new_av(ac, av);
	list = create_list();
	while (len)
	{
		len--;
		push_head(list, new_av[len]);
	}
	free(new_av);
	return (list);
}
