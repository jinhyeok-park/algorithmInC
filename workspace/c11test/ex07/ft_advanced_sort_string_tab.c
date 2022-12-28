/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:25:24 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/13 15:17:31 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		k;
	int		len;
	char	*temp;

	k = 0;
	temp = NULL;
	while (tab[len])
		len++;
	len--;
	while (i < len)
	{
		k = 0;
		while (k < len - i)
		{
			if (cmp(tab[k], tab[k + 1]))
			{
				temp = tab[k];
				tab[k] = tab[k + 1];
				tab[k + 1] = temp;
			}
			k++;
		}
		i++;
	}
}
