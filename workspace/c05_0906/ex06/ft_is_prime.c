/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:35:59 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/06 14:23:00 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	n;

	n = 2;
	if (nb < 2)
		return (0);
	while (n * n <= (long long)nb)
	{
		if ((long long)nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}
