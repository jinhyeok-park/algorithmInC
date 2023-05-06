/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:10:40 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/26 16:09:24 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_self_base(char *base)
{
	int		i;
	int		k;
	int		len;

	i = 0;
	while (base[i])
		i++;
	len = i;
	i = 0;
	while (i < len - 1)
	{
		k = i + 1;
		while (base[k])
		{
			if (base[k] == base[i])
				return (0);
			k++;
		}
		i++;
	}
	return (len);
}

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		else if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (ft_check_self_base(base));
}

int	ft_find_stpoint(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_return(char *str, char *base, int base_len, int sign)
{
	int			i;
	int			k;
	long long	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		k = 0;
		while (base[k])
		{
			if (str[i] == base[k])
			{
				result = result * base_len + k;
				break ;
			}
			k++;
		}
		if (k == base_len)
			return (result * sign);
		i++;
	}
	return (result * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	int			index;
	long long	result;
	int			base_len;
	int			i;

	sign = 1;
	result = 0;
	i = 0;
	base_len = ft_check_base(base);
	if (!base_len)
		return (0);
	index = ft_find_stpoint(str, &sign);
	return (ft_return(&str[index], base, base_len, sign));
}
