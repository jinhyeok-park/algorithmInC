/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <jinhyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:50:30 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/05 17:11:28 by jinhyepa         ###   ########.fr       */
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
		if (base[i] == '+' || base[i] == '-' || base[i] == 32)
			return (0);
		if (base[i] >= 9 && base[i] <= 13)
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

int	check_str_base(char ch, char *base)
{
	int		i;
	int		bl;

	bl = 0;
	i = 0;
	while (base[i])
	{
		if (ch == base[i])
			bl = 1;
		i++;
	}
	return (bl);
}

int	make_result(char *str, char *base, int startpoint, int basesize)
{
	int		i_base;
	int		result;

	result = 0;
	while (str[startpoint])
	{
		i_base = 0;
		while (base[i_base])
		{
			if (!check_str_base(base[i_base], base))
				return (result);
			if (base[i_base] == str[startpoint])
			{
				result = result * basesize + i_base;
				break ;
			}
			i_base++;
		}
		startpoint++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		basesize;
	int		sign;
	int		startpoint;

	sign = 1;
	basesize = check_base(base);
	startpoint = find_start_position(str, &sign);
	return (sign * make_result(str, base, startpoint, basesize));
}
