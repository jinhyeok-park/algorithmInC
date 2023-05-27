/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:21:14 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/26 15:55:53 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] != '\n')
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

void	iserror(char *temp, t_list_ps *lista, t_list_ps *listb)
{
	error_msg();
	free(temp);
	free(lista);
	free(listb);
	exit(0);
}
