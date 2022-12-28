/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:42:04 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/13 17:38:28 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (i < length)
	{
		if (f(tab[i]))
			result++;
		i++;
	}
	return (result);
}
