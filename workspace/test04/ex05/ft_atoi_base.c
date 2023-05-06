/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <jinhyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:50:30 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/04 19:10:07 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int		i;
	char	*check;
	int		k;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' && base[i] == '-' && base[i] == 32)
			return (0);
		k = i + 1;
		check = base;
		while (check[k])
		{
			if (check[k] == base[i])
				return (0);
			k++;
		}
		i++;
	}
	return (i);
}

int	find_start_position(char *str, int *sign)
{
	int		i;

	i = 0;
	while (str[i] <= 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
		{
			*sign = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
	}
	return (i);
}

int	make_result(char *str, char *base, int sign, int basesize)
{
	int		i_base;
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (str[i])
	{
		i_base = 0;
		while (base[i_base])
		{
			if (base[i_base] == str[i])
			{
				result = result * basesize + i_base;
				break ;
			}
			i_base++;
		}
		i++;
	}
	return (result * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int		basesize;
	int		sign;
	int		startpoint;

	sign = 1;
	basesize = check_base(base);
	startpoint = find_start_position(str, &sign);
	return (make_result(str, base, sign, basesize));
}
