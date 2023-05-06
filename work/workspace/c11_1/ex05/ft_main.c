/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:42:21 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/30 15:31:35 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nb);

void	ft_cal(int num1, int num2, char oper)
{
	if (oper == '-')
		ft_putnbr(num1 - num2);
	else if (oper == '+')
		ft_putnbr(num1 + num2);
	else if (oper == '/')
		ft_putnbr(num1 / num2);
	else if (oper == '%')
		ft_putnbr(num1 % num2);
	else if (oper == '*')
		ft_putnbr(num1 * num2);
	write(1, "\n", 1);
}

int	ft_err(int num2, char oper)
{
	if (oper == '%' && num2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	if (oper == '/' && num2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	return (0);
}

int	ft_opcheck(char *oper)
{
	if (!oper[1])
	{
		if (*oper == '-' || *oper == '+' || *oper == '/')
			return (0);
		if (*oper == '*' || *oper == '%')
			return (0);
	}
	return (1);
}

void	ft_start(char **av)
{
	int		num1;
	int		num2;
	char	*oper;
	void	(*cal[1])(int num1, int num2, char oper);

	cal[0] = ft_cal;
	num1 = ft_atoi(av[1]);
	num2 = ft_atoi(av[3]);
	oper = av[2];
	if (ft_opcheck(oper))
	{
		write(1, "0\n", 2);
		return ;
	}
	if (ft_err(num2, *oper))
		return ;
	cal[0](num1, num2, *oper);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	ft_start(av);
	return (0);
}
