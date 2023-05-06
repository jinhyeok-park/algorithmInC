/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:49:37 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/02/01 18:20:23 by sroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	ft_make_charmap(char *file, t_map *smap)
{
	int		i;

	i = 0;
	smap->c_map = (char **)malloc(sizeof(char *) * smap->row_size + 1);
	if (!smap->c_map)
	{
		free(smap->c_map);
		return ;
	}
	smap->c_map[smap->row_size] = 0;
	ft_make_charmap2(smap);
	ft_input_data(file, smap);
}

void	ft_make_charmap2(t_map *smap)
{
	int	i;

	i = 0;
	while (i < smap->row_size)
	{
		smap->c_map[i] = (char *)malloc(smap->col_size + 1);
		if (!(smap->c_map[i]))
		{
			while (i)
			{
				free(smap->c_map[i]);
				i--;
			}
			return ;
		}
		smap->c_map[i][smap->col_size] = 0;
		i++;
	}
}

void	ft_input_data(char *file, t_map *smap)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = 0;
	while (file[i] != '\n')
		i++;
	i++;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			k = 0;
			i++;
			j++;
		}
		if (!file[i])
			return ;
		smap->c_map[j][k] = file[i];
		k++;
		i++;
	}
}
