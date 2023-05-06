/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:20 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/31 17:33:32 by sroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print(t_map *smap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (smap->c_map[i])
	{
		j = 0;
		while (smap->c_map[i][j])
		{
			write(1, &smap->c_map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}