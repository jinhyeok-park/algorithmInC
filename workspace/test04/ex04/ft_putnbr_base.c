/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:20:38 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/04 22:25:00 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	to_base(char *base, long nbr, int size)
{
	if (size == 0)
		return (0);
	if (nbr > size - 1)
		to_base(base, nbr / size, size);
	write(1, &base[nbr % size], 1);
}

int	ft_chekc_self(char *base, int i)
{
	int		k;
	char	*check;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] <= 32 || base[i] == 127)
		return (0);
	while (base[i])
	{
		if ((base[i] == '-' || base[i] == '+'))
			return (0);
		check = base;
		k = i + 1;
		while (check[k])
		{
			if (check[k] == base[i])
				return (0);
			k++;
		}
		i++;
	}
	return (i);
}	

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	cpnbr;

	i = 0;
	cpnbr = (long)nbr;
	i = ft_chekc_self(base, i);
	if (i > 1)
	{
		if (nbr < 0)
		{
			cpnbr *= -1;
			write(1, "-", 1);
		}
		to_base(base, cpnbr, i);
	}
}
