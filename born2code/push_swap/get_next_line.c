/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:08:47 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:47:11 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd)
{
	char	*start;
	char	*point;

	start = malloc(10000);
	point = start;
	if (fd < 0)
		return (NULL);
	while (read(fd, point, 1) > 0)
	{
		if (*point == '\n')
			break ;
		point++;
	}
	if (point > start || *point == '\n')
	{
		if (point == start || *point == '\n')
			point++;
		*point = 0;
		return (start);
	}
	free(start);
	return (NULL);
}
