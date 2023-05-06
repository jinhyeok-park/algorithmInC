/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:47:10 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/14 12:13:17 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	print(int a, int b) {
    int	i;
    int	j;
	
	i = 1;
	j = 1;
    while (i<=b){
        while (j<=a){
            if (i==1)
			{
                if (j==1)
				{
                    ft_putchar('A');
                }
                else if (j==a)
				{
                    ft_putchar('C');
                }
                else
			   	{
                    ft_putchar('B');
                }
            }
            else if(i==b)
		   	{
                if (j==1)
				{
                    ft_putchar('C');
                }
                else if (j==a)
				{
                    ft_putchar('A');
                }
                else
				{
                    ft_putchar('B');
                }
            }
            else
			{
                if(j==1 || j==a)
				{
                    ft_putchar('B');
                }
                else
				{
                    ft_putchar(' ');
                }
            }
            j++;
        }
        printf("\n");
        i++;
        j = 1;
    }
}

void	rush(int a, int b)
{
    if (!(a<=0 || b<=0))
        print(a,b);
}

int main(void)
{
    rush(5, 3);
    return (0);
}
