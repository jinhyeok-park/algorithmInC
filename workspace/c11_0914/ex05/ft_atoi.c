/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:14:02 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/06 13:23:20 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	strpoint(int i, char *str)
{
	while (str[i] <= 32)
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	int		n;
	int		result;

	i = 0;
	n = 1;
	result = 0;
	i = strpoint(i, str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			n *= -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * n);
}
