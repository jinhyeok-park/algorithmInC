/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:43:30 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/05 21:51:18 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt(int nb)
{
	long long	i;

	i = 2;
	while (i * i <= (long long)nb)
	{
		if ((long long)nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int get_prime(int nb)
{
	int		i;

	i = 0;
	if (nb < 2)
		return (2);
	while (!ft_sqrt(nb))
		nb++;
	return (nb);
}
