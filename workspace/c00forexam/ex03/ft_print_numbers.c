/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:00:31 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/08/27 22:17:34 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{	
	char	count;

	count = '0';
	while (count <= '9')
	{
		write(1, &count, 1);
		count++;
	}
}