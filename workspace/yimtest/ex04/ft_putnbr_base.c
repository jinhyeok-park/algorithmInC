/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yim <yim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:03:02 by yim               #+#    #+#             */
/*   Updated: 2022/09/03 16:38:48 by yim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{	
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	base_len;
	int	i;
	int	j;

	base_len = ft_strlen(base);
	i = 0;
	if (base[0] == '\0' || base_len == 1)
		return (0);
	while (base[i])
	{
		if ((base[i] <= 13 && base[i] >= 9) || base[i] == 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (base_len);
}

void	recursion(int nbr, int base_len, char *base)
{
	long	nbr2;

	nbr2 = (long)nbr;
	if (nbr2 < 0)
	{
		write(1, "-", 1);
		nbr2 *= -1;
	}
	if (nbr2 / base_len)
	{
		recursion(nbr2 / base_len, base_len, base);
	}
	write(1, &base[nbr2 % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		base_len;

	i = 0;
	base_len = check_base(base);
	if (base_len != 0)
	{
		recursion(nbr, base_len, base);
	}
}
/*
#include <stdio.h>
int	main(void)
{
	ft_putnbr_base(10, "01");
}
*/
