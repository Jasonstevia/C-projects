/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:50:04 by jslim             #+#    #+#             */
/*   Updated: 2025/09/17 17:58:23 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int u)
{
	int		count;
	long	n;
	char	c;

	count = 0;
	n = u;
	if (n >= 10)
		count += ft_print_unbr(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
	count++;
	return (count);
}

int	handle_specifier(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char((char)va_arg(args, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_print_unbr(va_arg(args, unsigned int));
	else if (specifier == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (specifier == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (specifier == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_specifier(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end (args);
	return (count);
}

// int main()
// {
// 	char string[] = "World";
// 	int decimal = 42;
// 	ft_printf("Hello %s: %d", string, decimal);
// 	return 0;
// }
