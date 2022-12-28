/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:37:46 by chanson           #+#    #+#             */
/*   Updated: 2022/08/28 20:31:29 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_putchar(char c);

void	print_x(int n1, int n2, int k)
{
	int		x;

	x = 0;
	while (x < n1 && n1 > 0 && n2 > 0)
	{
		if ((x == 0 || x == n1 - 1) && k == 1)
		{
			ft_putchar('A');
		}
		else if ((x == 0 || x == n1 - 1) && k == 0)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		x++;
	}
	ft_putchar('\n');
}

void	print_y(int n1)
{
	int		i;

	ft_putchar('B');
	i = 1;
	if (n1 > 1)
	{
		while (i < n1 - 1)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('B');
	}
}

int	rush(int n1, int n2)
{
	int		i;

	i = 0;
	print_x(n1, n2, 1);
	if (n2 > 2 && n1 > 0)
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
		print_x(n1, n2, 0);
	}
	return (0);
}
