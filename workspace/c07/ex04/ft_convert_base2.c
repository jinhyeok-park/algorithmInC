/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:34:30 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/14 19:03:48 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base, char str)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_positive(char c, int positive)
{
	if (c == '-')
		positive *= -1;
	return (positive);
}

int	ft_atoi(char *str, int base_len, char *base)
{
	int	i;
	int	positive;
	int	result;
	int	check;

	result = 0;
	i = 0;
	positive = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		positive = ft_positive(str[i], positive);
		i++;
	}
	while (str[i] && check_base(base, str[i]) != -1)
	{
		check = check_base(base, str[i]);
		result = result * base_len + check;
		i++;
	}
	return (result * positive);
}

int	ft_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if ((base[i] <= 13 && base[i] >= 9) || base[i] == 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1 || base[0] == 0)
		return (0);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	result;

	base_len = ft_base_len(base);
	if (base_len == 0)
		return (0);
	result = ft_atoi(str, base_len, base);
	return (result);
}
