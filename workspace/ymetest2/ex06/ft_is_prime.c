/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yim <yim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:52:41 by yim               #+#    #+#             */
/*   Updated: 2022/09/04 09:46:26 by yim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	n;

	n = 2;
	if (nb <= 1)
		return (0);
	while (n * n <= (long long)nb)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_is_prime(97));
}
*/
