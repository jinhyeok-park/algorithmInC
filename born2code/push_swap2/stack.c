/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:38:54 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:14:13 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*make_list(int ac, char **av, int len)
{
	long long	*new_av;
	t_list_ps	*list;

	new_av = make_new_av(ac, av);
	if (!new_av)
		return (0);
	list = create_list();
	if (!list)
		return (0);
	while (len)
	{
		len--;
		if (!push_head(list, new_av[len]))
			return (0);
	}
	return (list);
}
