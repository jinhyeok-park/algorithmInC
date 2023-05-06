/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:34:51 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/18 16:02:46 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_check_self_base(char *base)
{
	int		i;
	int		k;
	int		len;

	i = 0;
	while (base[i])
		i++;
	len = i;
	i = 0;
	while (i < len - 1)
	{
		k = i + 1;
		while (base[k])
		{
			if (base[k] == base[i])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] >= 9 && base[i] <= 13)
			return (0);
		else if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (ft_check_self_base(base));
}

void	ft_print_base(long long nbr, char *base, int len)
{
	if (nbr > len - 1)
		ft_print_base(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	num;
	int			sign;
	int			len;

	sign = 1;
	len = 0;
	num = (long long)nbr;
	if (!ft_check_base(base))
		return ;
	while (base[len])
		len ++;
	if (num < 0)
	{
		sign = -1;
		num *= -1;
		write(1, "-", 1);
	}
	ft_print_base(num, base, len);
}
