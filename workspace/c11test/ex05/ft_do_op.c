/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:28:35 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/13 11:52:48 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_jh.h"

void	ft_do_op(char **argv)
{
	if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	if (argv[2][0] == '+')
		ft_putnbr(ft_atoi(argv[1]) + ft_atoi(argv[3]));
	else if (argv[2][0] == '-')
		ft_putnbr(ft_atoi(argv[1]) - ft_atoi(argv[3]));
	else if (argv[2][0] == '*')
		ft_putnbr(ft_atoi(argv[1]) * ft_atoi(argv[3]));
	else if (argv[2][0] == '/')
		ft_putnbr(ft_atoi(argv[1]) / ft_atoi(argv[3]));
	else if (argv[2][0] == '%')
		ft_putnbr(ft_atoi(argv[1]) % ft_atoi(argv[3]));
	else
		ft_putnbr(0);
	ft_putchar('\n');
}
