/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:31:27 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:32:06 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list_ps	*list;
	int			len;

	len = av_count(ac, av);
	if (!check_input(ac, av) || (len == 1 && ac > len + 1))
	{
		error_msg();
		return (0);
	}
	if (ac < 2 || len < 2)
		return (0);
	list = make_list(ac, av, len);
	if (!list)
		return (0);
	if (issorting(list))
		exit(0);
	sorting(list);
}
