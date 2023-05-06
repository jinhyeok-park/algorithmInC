// s c d x X p % i
//
#include <unistd.h>
#include <stdarg.h>

int ft_printf(char *str, ...);
int	groupby(char c, va_list ap);
int	write_s(va_list ap);
int	write_di(va_list ap);
void	printf_num(long long num, int base);

int ft_printf(char *str, ...)
{
	int	i;
	int	len;
	va_list ap;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += groupby(*(str + 1 + i++ ), ap);
		else
			len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	write_s(va_list ap)
{
	char	*str;
	int		len;
	int		i;

	str = 0;
	len = 0;
	i = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	while (str[i])
		len += write(1, &str[i++], 1);
	return (len);
}

void	printf_num(long long num, int base)
{
	if (base == 10)
	{
		if (num > 9)
			printf_num(num / base, base);
		write(1, &"0123456789"[num % base], 1);
	}
	else if (base == 16)
	{
		num = (unsigned long long)num;
		if (num > 15)
			printf_num(num / base, base);
		write(1, &"0123456789abcdef"[num % base], 1);
	}
}

int	write_di(va_list ap)
{
	long long	num;
	int	len;

	num = va_arg(ap, int);
	len = 0;
	if (num < 0)
	{
		num *= -1;
		len += write(1, "-", 1);
	}
	printf_num(num, 10);
	return (0);
}

int	write_x(va_list ap)
{
	unsigned int temp;

	temp = va_arg(ap, int);
	printf_num(temp, 16);
	return (0);
}

int	write_p(va_list ap)
{
	unsigned long long temp;

	write (1, "0x", 2);
	temp = (long long)va_arg(ap, void *);
	printf_num(temp, 16);
	return (0);
}

int	groupby(char c, va_list ap)
{
	if (c == 's')
		return (write_s(ap));
	else if( c == 'c')
	{
		char	temp;

		temp = va_arg(ap, int);
		return (write(1, &temp, 1));
	}
	else if (c == 'd' || c == 'i')
		return (write_di(ap));
	else if (c == 'x')
		return (write_x(ap));
	else if (c == 'p')
		return (write_p(ap));
	return (0);
}

#include <stdio.h>
int main(void)
{
	char *str;
	int		count;

	str = "tse";
	count = 0;
	count = ft_printf("test\n");
	printf("%d \n" , count);
	count = ft_printf("this is string %s\n", str);
	printf("%d \n" , count);
	count = ft_printf("this is char %c\n", 'c');
	printf("%d \n" , count);
	count = ft_printf("this is d, i  %d\n", -2147483648);
	printf("%d \n" , count);
	count = ft_printf("this is x %x\n", -1);
	printf("%d \n" , count);
	count = ft_printf("this is p %p\n", str);
	printf("this is origin%p\n" , str);
	printf("%d \n" , count);
}
