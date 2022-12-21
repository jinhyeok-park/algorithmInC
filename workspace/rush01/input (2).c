/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:15:57 by seycho            #+#    #+#             */
/*   Updated: 2022/09/03 20:26:06 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**parse_input(char *str, int n)
{
	int	i;
	int	j;
	int	k;
	int	**parsed_inputs;

	i = 0;
	j = 0;
	k = 0;
	parsed_inputs = (int **)malloc(sizeof(int) * 4 * n);
	parsed_inputs[0] = (int *)malloc(sizeof(int) * n);
	parsed_inputs[1] = (int *)malloc(sizeof(int) * n);
	parsed_inputs[2] = (int *)malloc(sizeof(int) * n);
	parsed_inputs[3] = (int *)malloc(sizeof(int) * n);
	while (i < str_len(str))
	{
		if (j == n)
		{
			j++;
			k = 0;
		}
		parsed_inputs[j][k] = str[i] - '0';
		k++;
		i += 2;
	}
	return (parsed_inputs);
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_input(char *str, int n)
{
	int	num_cnt;
	int	i;

	num_cnt = 0;
	i = 0;
	if (str_len(str) != (n * 8 - 1))
		return (0);
	while (i < str_len(str))
	{
		if (i % 2 == 0)
		{
			if (!(str[i] >= '1' && str[i] <= (n + '0')))
				return (0);
		}
		else
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}
