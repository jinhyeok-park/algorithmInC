/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:10:43 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/20 20:47:57 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprime(int nb)
{
	int	i;

	i = 2;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (i);
		i++;
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	while (ft_isprime(nb))
		nb++;
	return (nb);
}
