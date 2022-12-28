/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:25:51 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/08/28 13:49:34 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		temp;

	temp = 0;
	i = 0;
	while (i < (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[size - (1 + i)];
		tab[size - (1 + i)] = temp;
		i++;
	}
}
