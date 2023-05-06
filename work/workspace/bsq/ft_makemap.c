/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:51:20 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/02/01 18:20:37 by sroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_map	*ft_make_s_map(char *charset)
{
	t_map	*result;

	result = (t_map *)malloc(sizeof(t_map));
	if (!result)
	{
		free(result);
		return (0);
	}
	result->row_size = 0;
	result->col_size = 0;
	result->charmem = charset;
	return (result);
}

t_map	*ft_make_map1(char *file, char *charset)
{
	t_map	*smap;
	int		row_len;

	row_len = ft_check_num(file);
	smap = ft_make_s_map(charset);
	smap->map = (int **)malloc(sizeof(int *) * row_len);
	if (!smap->map)
	{
		free(smap->map);
		return (0);
	}
	smap->row_size = row_len;
	return (ft_make_map2(smap, row_len, file));
}

t_map	*ft_make_map2(t_map *smap, int row_len, char *file)
{
	int		i;
	int		col_len;

	col_len = ft_check_row(file);
	i = 0;
	while (i < row_len)
	{
		smap->map[i] = (int *)malloc(sizeof(int) * col_len);
		if (!smap->map[i])
		{
			while (i--)
				free(smap->map[i]);
			return (0);
		}
		i++;
	}
	smap->col_size = col_len;
	ft_make_charmap(file, smap);
	return (ft_init_map(smap));
}

t_map	*ft_init_map(t_map *smap)
{
	int	i;
	int	j;

	i = 0;
	while (i < smap->row_size)
	{
		j = 0;
		while (j < smap->col_size)
		{
			smap->map[i][j] = -1;
			j++;
		}
		i++;
	}
	return (smap);
}
