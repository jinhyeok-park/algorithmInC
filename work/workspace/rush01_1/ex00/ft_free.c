/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:33:11 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/22 20:00:56 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_free(int **map, int **base)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(map[i]);
		free(base[i]);
		i++;
	}
	free(map);
	free(base);
}
