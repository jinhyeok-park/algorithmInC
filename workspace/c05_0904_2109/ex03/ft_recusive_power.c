/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recusive_power.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:39:22 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/04 21:51:59 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if(nb < 0)
		return (0);
	if(nb == 0 && power == 0)
		return (1);
	if(power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, --power));
}
