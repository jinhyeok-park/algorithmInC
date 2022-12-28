/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:59:02 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 03:36:28 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush02.h"

int	cnt_dict_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
}

int	check_if_zeros(char *nums)
{
	int	cnt_zero;
	int	i;

	cnt_zero = 0;
	i = 0;
	while (i < 3)
	{
		if (*nums == '0')
			cnt_zero++;
		nums++;
		i++;
	}
	if (cnt_zero == 3)
		return (1);
	return (0);
}

int	check_has_next(char **nums, int pos)
{
	while (nums[++pos])
	{
		if (nums[pos][0] != '0' || nums[pos][1] != '0' || nums[pos][2] != '0')
			return (1);
	}
	return (0);
}

int	print_full_num(t_dict *dict, char **nums)
{
	int	has_next;
	int	len;
	int	i;

	len = cnt_dict_nums(nums) + 1;
	if (len == 2 && check_if_zeros(nums[0]))
	{
		ft_print_str(dict->ones[0], 0);
		ft_putchar('\n');
		return (1);
	}
	i = 0;
	while (--len > 0)
	{
		if (check_if_zeros(nums[i]) == 0)
		{
			has_next = check_has_next(nums, i);
			ft_print_unit(dict, nums[i], len, has_next);
			if (len > 1)
				ft_print_str(dict->thousands[len - 1], has_next);
		}
		i++;
	}
	ft_putchar('\n');
	return (1);
}

int	ft_print_num(t_dict *dict, char *input)
{
	char	**nums;
	int		i;

	nums = ft_split(input);
	if (!nums)
		return (0);
	print_full_num(dict, nums);
	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
	return (1);
}
