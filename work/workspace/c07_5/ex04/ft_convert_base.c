/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:06:51 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/26 16:09:14 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_len(char *str);
int	ft_check_base(char *base);

int	ft_num_len(long long num, char *base_to, int sign)
{
	int	base_len;
	int	count;

	base_len = ft_len(base_to);
	count = 0;
	if (sign == -1)
		count++;
	while (num > 0)
	{
		num /= base_len;
		count++;
	}
	return (count);
}	

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_result(char *result, long long num, char *base_to, int sign)
{
	int	i;
	int	base_len;

	i = 0;
	base_len = ft_len(base_to);
	while (num > 0)
	{
		result[i] = base_to[num % base_len];
		num /= base_len;
		i++;
	}
	if (sign == -1)
	{
		result[i] = '-';
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_len(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;
	int			sign;
	char		*result;

	sign = 1;
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	num = (long long)ft_atoi_base(nbr, base_from);
	if (num == 0)
	{
		result = (char *)malloc(2);
		result[0] = base_to[0];
		result[1] = '\0';
		return (result);
	}
	if (num < 0)
	{
		sign = -1;
		num *= -1;
	}
	result = (char *)malloc(ft_num_len(num, base_to, sign) + 1);
	if (!result)
		return (0);
	result = ft_strrev(ft_result(result, num, base_to, sign));
	return (result);
}
