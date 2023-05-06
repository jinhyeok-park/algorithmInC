/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:34:23 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/07 20:37:06 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base, int base_from_len, int *sign);
int	ft_strlen(char *str);
int	base_check(char *base);

char	*ft_strrev(char *str)
{
	int		start;
	int		end;
	char	tmp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	return (str);
}

int	malloc_len(long long num, int base_to_len)
{
	int		len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num)
	{
		len ++;
		num /= (long long)base_to_len;
	}
	return (len);
}

char	*zero(char *res, char *base_to)
{
	res[0] = base_to[0];
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int nbr_i, char *base_to, int base_to_len, int sign)
{
	char		*res;
	long long	num;
	int			i;

	num = (long long)nbr_i;
	i = 0;
	res = (char *)malloc(sizeof(char) * (malloc_len(num, base_to_len) + 1));
	if (!res)
		return (NULL);
	if (num == 0)
	{
		res = (char *)malloc(sizeof(char) + 1);
		if (!res)
			return (NULL);
		return (zero(res, base_to));
	}
	while (num)
	{
		res[i++] = base_to[num % base_to_len];
		num /= base_to_len;
	}
	if (sign == -1)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_strrev(res));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		nbr_i;
	int		base_from_len;
	int		base_to_len;
	char	*result;

	sign = 1;
	base_from_len = base_check(base_from);
	base_to_len = base_check(base_to);
	if (base_check(base_from) == 0 || base_check(base_to) == 0)
		return (NULL);
	nbr_i = ft_atoi_base(nbr, base_from, base_from_len, &sign);
	result = ft_itoa(nbr_i, base_to, base_to_len, sign);
	return (result);
}

#include <stdio.h>

int main(void)
{
	printf("%s", ft_convert_base("-2147483647","0123456789","ab"));
}

