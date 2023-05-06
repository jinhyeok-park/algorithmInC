/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:11:28 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/13 09:37:05 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **src);

int	ft_strcmp(char *dest, char *src)
{
	int		i;

	i = 0;
	while (dest[i] || src[i])
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		i++;
	}
	return (0);
}

void	ft_swap(char **str)
{
	int		i;
	int		k;
	char	*temp;

	k = 0;
	temp = NULL;
	while (str[k])
	{
		i = k + 1;
		while (str[i])
		{
			if (ft_strcmp(str[k], str[i]) > 0)
			{
				temp = str[k];
				str[k] = str[i];
				str[i] = temp;
			}
			i++;
		}
		k++;
	}
}
