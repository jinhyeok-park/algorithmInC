/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yim <yim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:20:23 by yim               #+#    #+#             */
/*   Updated: 2022/09/11 21:19:00 by yim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	do_op(char **argv)
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
