/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:37:46 by chanson           #+#    #+#             */
/*   Updated: 2022/08/28 20:36:43 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_putchar(char c);

void	print_x(int n)
{
	int		x;

	x = 0;
	while (x < n)
	{
		if (x == 0 || x == n - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		x++;
	}
	ft_putchar('\n');
}

void	print_y(int n1)
{
	int		i;

	ft_putchar('|');
	i = 1;
	if (n1 > 1)
	{
		while (i < n1 - 1)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('|');
	}
}

int	rush(int n1, int n2)
{
	int		i;

	i = 0;
	print_x(n1);
	if (n2 > 2)
	{
		while (i < n2 - 2)
		{
			print_y(n1);
			ft_putchar('\n');
			i++;
		}
	}
	if (n2 > 1)
	{
		print_x(n1);
	}
	return (0);
}
