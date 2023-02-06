/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:27:12 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/29 05:47:38 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
			if (needle[j] == '\0')
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
	char	*p;

	if (!sep_num)
		return ;
	num_of_zero = 3 * sep_num;
	n -= num_of_zero;
	if (*(n - 1) == '0' && *(n - 2) == '0' && *(n - 3) == '0')
		return ;
	needle = ft_makillion(num_of_zero);
	p = ft_strstr(dict, needle);
	free(needle);
	while (*p >= '0' && *p <= '9')
		p++;
	while (*p == ' ' || *p == ':')
		p++;
	while (*p != '\n')
		write(1, p++, 1);
	num_of_zero = 0;
	while (n[num_of_zero] == '0' && num_of_zero < 3 * sep_num)
		num_of_zero++;
	if (n[num_of_zero] != '\0')
		write(1, " ", 1);
}
