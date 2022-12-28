/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:11:28 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/13 21:11:56 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		k;
	char	*temp;

	k = 0;
	temp = NULL;
	while (tab[k])
	{
		i = k + 1;
		while (tab[i])
		{
			if (ft_strcmp(tab[k], tab[i]) > 0)
			{
				temp = tab[k];
				tab[k] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		k++;
	}
}
