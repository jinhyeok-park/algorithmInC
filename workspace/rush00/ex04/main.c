/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:29:21 by chanson           #+#    #+#             */
/*   Updated: 2022/08/28 22:34:10 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	rush(int n1, int n2);

int	is_digit(char num[])
{
	int	i;
	int	n;

	i = 0;
	while (num[i] != '\0')
	{
		n = num[i] - '0';
		if (num[i] < 48 || num[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	a_to_i(char num[])
{
	int	i;
	int	n;
	int	j;

	i = 0;
	while (num[i])
		i++;
	j = 1;
	n = 1;
	while (n < i)
	{
		j *= 10;
		n++;
	}
	i = 0;
	n = 0;
	while (j >= 1)
	{
		n += (num[i] - '0') * j;
		j /= 10;
		i++;
	}
	return (n);
}

int	main(int argc, char *argv[])
{
	int		sw_1;
	int		sw_2;

	sw_1 = 0;
	sw_2 = 0;
	if (argc == 3)
	{
		if (is_digit(argv[1]))
		{	
			sw_1 = 1;
		}
		if (is_digit(argv[2]))
			sw_2 = 1;
		if (sw_1 && sw_2)
		{
			sw_1 = a_to_i(argv[1]);
			sw_2 = a_to_i(argv[2]);
			rush(sw_1, sw_2);
		}
		else
			write(1, "input error!", 12);
	}
	else
		write(1, "input error!", 12);
	return (0);
}
