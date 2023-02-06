/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:36:48 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/02/01 14:05:01 by sroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_free(t_map *smap)
{
	int	i;

	i = 0;
	while (i < smap->row_size)
	{
		free(smap->map[i]);
		free(smap->c_map[i]);
		i++;
	}
	free(smap->c_map);
	free(smap->map);
	free(smap->charmem);
	free(smap);
}
