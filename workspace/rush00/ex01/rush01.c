/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:37:46 by chanson           #+#    #+#             */
/*   Updated: 2022/08/28 20:34:54 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern	void	ft_putchar(char c);

void	print_x1(int n)
{
	int		x;

	x = 0;
	while (x < n)
	{
		if (x == 0)
		{
			ft_putchar('/');
		}
		else if (x == n - 1)
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('*');
		}
		x++;
	}
	ft_putchar('\n');
}

void	print_x2(int n)
{
	int		x;

	x = 0;
	while (x < n)
	{
		if (x == 0)
		{
			ft_putchar('\\');
		}
		else if (x == n - 1)
		{
			ft_putchar('/');
		}
		else
		{
			ft_putchar('*');
		}
		x++;
	}
}

void	print_y(int n1)
{
	int		i;

	ft_putchar('*');
	i = 1;
	if (n1 > 1)
	{
		while (i < n1 - 1)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('*');
	}
}

int	rush(int n1, int n2)
{
	int		i;

	i = 0;
	print_x1(n1);
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
		print_x2(n1);
	}
	return (0);
}
