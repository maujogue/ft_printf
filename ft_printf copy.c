/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:38:41 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/27 16:40:07 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (*str++)
        i++;
    return (i);
}

void	ft_putchar_count(char c, int *count, int n)
{
	write(1, &c, 1);
	*count += n;
}

void	ft_putstr_count(char *s, int *count)
{
	int	i;

	i = -1;
	if (s != NULL)
	{
		while (s[++i])
			ft_putchar_count(s[i], count, 1);
	}
	else
		ft_putstr_count("(null)", count);
}
void	ft_putnbr_digit(long long nb, char *base, int *count)
{
	long long	length;

    if (nb < 0)
    {
        nb = nb * -1;
        ft_putchar_count('-', count, 0);
        *count += 1;
    }
	length = ft_strlen(base);
	if (nb >= length)
		ft_putnbr_digit(nb / length, base, count);
	ft_putchar_count(base[nb % length], count, 1);
}

static int	write_arg(const char *str, int i, va_list args, int *count)
{
	if (str[i] == '%' && str[i + 1])
	{
		if (str[i + 1] == 's')
			ft_putstr_count((char *)va_arg(args, char *), count);
		else if (str[i + 1] == 'd')
			ft_putnbr_digit(va_arg(args, int),
				"0123456789", count);
		else if (str[i + 1] == 'x')
			ft_putnbr_digit(va_arg(args, unsigned int),
				"0123456789abcdef", count);
		else
			ft_putchar_count(str[i + 1], count, 1);
		return (i + 1);
	}
	else if (!(str[i] == '%' && str[i]))
		ft_putchar_count(str[i], count, 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		y;
	int		count;
	va_list	args;

	i = -1;
	count = 0;
	va_start(args, str);
	y = write(1, 0, 0);
	if (y < 0)
		return (-1);
	while (str[++i])
		i = write_arg(str, i, args, &count);
	va_end(args);
	return (count);
}

int main(void){
   	int n = -10893025;
    printf("%d",ft_printf("%xsa%",n));
	printf("%d",printf("\n%xsa%",n));
}