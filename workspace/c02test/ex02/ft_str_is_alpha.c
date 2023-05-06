/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:10:13 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/08/30 13:18:16 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		bl;

	i = 0;
	bl = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			bl = 1;
		else if (str[i] >= 97 && str[i] <= 122)
			bl = 1;
		else
			return (0);
		i++;
	}
	if (str[i] == '\0')
		bl = 1;
	if (bl)
		return (1);
	else
		return (0);
}
