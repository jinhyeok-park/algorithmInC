/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:29:15 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/05 15:41:05 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int ac, char *av[])
{
	int		i;
	int		k;

	k = 1;
	if (ac > 1)
	{
		while (av[k])
		{
			i = 0;
			while (av[k][i])
			{
				write(1, &av[k][i], 1);
				i++;
			}
			k++;
			write(1, "\n", 1);
		}
	}
	return (0);
}
