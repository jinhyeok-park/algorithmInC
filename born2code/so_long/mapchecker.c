/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:23:18 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/26 20:21:54 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *map_maker(char *map_name)
{
	t_map	*map;

	map = NULL;
	if (map_errorcheck(map_name))
	{
		map = (t_map *)malloc(sizeof(t_map *));
		if(create_map(map_name, &map))
			return (NULL);
	}
	return (map);
}

size_t map_errorcheck(char *map_name)
{


}

int	head_tail_line_checker(char *line)
{

}