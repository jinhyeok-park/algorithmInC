/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:34:30 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/07 20:37:51 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi(char *str, int *sign)
{
	int	pos;

	pos = 0;
	while ((9 <= str[pos] && str[pos] <= 13) || str[pos] == 32)
		pos++;
	while (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '-')
			*sign *= -1;
		pos++;
	}
	return (pos);
}

int	base_check(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = ft_strlen(base);
	if (base[0] == '\0' || base_len == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((9 <= base[i] && base[i] <= 13) || base[i] == 32)
			return (0);
		i++;
	}
	return (base_len);
}

int	get_result(char *str, int str_pos, char *base, int base_len)
{
	int	i;
	int	res;

	res = 0;
	while (str[str_pos] != '\0')
	{
		i = 0;
		while (base[i] != '\0')
		{
			if (str[str_pos] == base[i])
			{
				res = res * base_len + i;
				break ;
			}
			i++;
		}
		if (base[i] == '\0')
			return (res);
		str_pos++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base, int base_from_len, int *sign)
{
	int	str_pos;
	int	res;

	if (base_from_len > 1)
	{
		str_pos = ft_atoi(str, sign);
		res = get_result(str, str_pos, base, base_from_len);
		return (res);
	}
	else
		return (0);
}