/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:50:18 by jslim             #+#    #+#             */
/*   Updated: 2025/09/18 08:17:20 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_ptr(void *p)
{
	int				count;
	unsigned long	addr;

	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	write(1, "0x", 2);
	addr = (unsigned long) p;
	count += ft_print_hex((unsigned long)addr, "0123456789abcdef");
	return (count);
}

int	ft_print_nbr(int d)
{
	long	i;
	int		count;
	char	c;

	count = 0;
	i = d;
	if (i < 0)
	{
		i = -i;
		write (1, "-", 1);
		count++;
	}
	if (i >= 10)
		count += ft_print_nbr(i / 10);
	c = i % 10 + '0';
	write (1, &c, 1);
	count++;
	return (count);
}

int	ft_print_hex(unsigned long x, char *base)
{
	int		count;
	char	c;

	count = 0;
	if (x >= 16)
		count += ft_print_hex(x / 16, base);
	c = base[x % 16];
	write (1, &c, 1);
	count++;
	return (count);
}
