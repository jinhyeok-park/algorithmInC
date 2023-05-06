/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:49:21 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/02/01 18:03:34 by sroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_line(char *file)
{
	int	i;
	int	count;
	int	num;

	i = 0;
	count = 0;
	num = ft_check_num(file);
	while (file[i] != '\n')
		i++;
	i++;
	if (file[i] == 0)
		return (0);
	while (file[i])
	{
		if (file[i] == '\n')
		{
			count++;
			i++;
		}
		i++;
	}
	if (count != num || !num || !ft_check_row(file))
		return (0);
	return (1);
}
