/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:10:38 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/04 21:23:09 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		i;
	int		result;

	if(nn < 0)
		return (0);
	i = 0;
	result = 1;
	while (i < nb)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
