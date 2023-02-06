/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:33:29 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/15 16:46:29 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len;

	i = 0;
	len = ft_len(to_find);
	if (len == 0)
		return (str);
	while (str[i])
	{
		if (!ft_ncmp(&str[i], to_find, len))
			return (&str[i]);
		i++;
	}
	return (0);
}
