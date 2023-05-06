/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:27:12 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/28 22:37:12 by heewoopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_no_comma(char *num, int j)
{
	int		i;
	int		len;
	char	*n;
// 인수로 받은 num 은 첫번째 '1' ~ '9' 에 대한 주소.
	len = ft_strlen(num);
	i = 0;
	while (num[i])
	{
		if (num[i] == ',')
			j++;
		i++;
	}
	n = malloc(len - j + 1);
	i = (num[0] == '+') + (num[0] != '+') * 0;
	j = 0;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			n[j++] = num[i];
		i++;
	}
	n[j] = '\0';
	return (n);
}

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	j;

	if (needle[0] == '\0')
		return (haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (!(needle[j]))
				return (haystack + i);
		}
		i++;
	}
	return (0);
}

char	*ft_makillion(int num_of_zero)
{
	char	*d;
	int		i;

	d = malloc(num_of_zero + 2);
	d[0] = '1';
	i = 1;
	while (num_of_zero)
	{
		d[i] = '0';
		num_of_zero--;
		i++;
	}
	d[i] = '\0';
	return (d);
}

void	ft_print_sep(char *dict, char *n, int sep_num)
{
	int		num_of_zero;
	char	*needle;

	if (!sep_num)
		return ;
	num_of_zero = 3 * sep_num;
	while (*n)
		n++;
	n -= num_of_zero;
	if (*(n - 1) == '0' && *(n - 2) == '0' && *(n - 3) == '0')
		return ;
	needle = ft_makillion(num_of_zero);
	needle = ft_strstr(dict, needle);
	while (*needle >= '0' && *needle <= '9')
		needle++;
	while (*needle == ' ' || *needle == ':')
		needle++;
	while (*needle != '\n')
	{
		write(1, needle, 1);
		needle++;
	}
	write(1, " ", 1);
}
