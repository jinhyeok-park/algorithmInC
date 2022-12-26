/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yim <yim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 08:08:20 by yim               #+#    #+#             */
/*   Updated: 2022/09/11 17:55:58 by yim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	ft_putnbr(int nb)
{
	long	lnb;

	lnb = (long)nb;
	if (lnb < 0)
	{
		ft_putchar('-');
		lnb = -lnb;
	}	
	if (lnb / 10)
	{
		ft_putnbr(lnb / 10);
	}
	ft_putchar(lnb % 10 + '0');
}