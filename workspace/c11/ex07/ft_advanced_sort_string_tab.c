/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:25:24 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/13 18:06:00 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		k;
	int		len;

	k = 0;
	i = 0;
	len = 0;
	while (tab[len])
		len++;
	len--;
	while (i < len)
	{
		k = 0;
		while (k < len - i)
		{
			if (cmp(tab[k], tab[k + 1]) > 0)
			{
				ft_swap (&tab[k], &tab[k + 1]);
			}
			k++;
		}
		i++;
	}
}
