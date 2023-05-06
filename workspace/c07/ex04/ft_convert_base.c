/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:34:23 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/14 19:12:55 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_base_len(char *base);
int	ft_positive(char c, int positive);
int	check_base(char *base, char str);
int	ft_atoi(char *str, int base_len, char *base);

int	ft_malloc_len(int decimal, int base_to_len)
{
	int		cnt;
	long	decimal_long;

	decimal_long = (long)decimal;
	cnt = 0;
	if (decimal == 0)
		return (1);
	if (decimal_long < 0)
	{
		cnt++;
		decimal_long *= -1;
	}
	while (decimal_long)
	{
		cnt ++;
		decimal_long /= base_to_len;
	}
	return (cnt);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

char	*decimal_zero(char *result, char *base_to)
{
	result[0] = base_to[0];
	result[1] = '\0';
	return (result);
}

char	*ft_make_base_to(char *result, int decimal, char *base_to, int len)
{
	int		i;
	int		flag;
	long	decimal_long;

	decimal_long = (long)decimal;
	i = 0;
	if (decimal_long == 0)
		return (decimal_zero(result, base_to));
	if (decimal_long < 0)
	{
		flag = 1;
		decimal_long *= -1;
	}
	while (decimal_long)
	{
		result[i++] = base_to[decimal_long % len];
		decimal_long /= len;
	}
	if (flag == 1)
	{
		result[i] = '-';
		i++;
	}
	result[i] = '\0';
	return (ft_strrev(result));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal;
	int		base_to_len;
	int		malloc_len;
	char	*result;

	base_to_len = ft_base_len(base_to);
	if (base_to_len == 0 || ft_base_len(base_from) == 0)
		return (NULL);
	decimal = ft_atoi_base(nbr, base_from);
	malloc_len = ft_malloc_len(decimal, base_to_len);
	result = (char *)malloc(sizeof(char) * (malloc_len + 1));
	if (result == NULL)
		return (NULL);
	result = ft_make_base_to(result, decimal, base_to, base_to_len);
	return (result);
}
