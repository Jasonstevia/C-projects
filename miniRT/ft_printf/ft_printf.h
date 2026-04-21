/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:50:33 by jslim             #+#    #+#             */
/*   Updated: 2025/09/18 08:21:13 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		handle_specifier(char specifier, va_list args);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_ptr(void *p);
int		ft_print_nbr(int d);
int		ft_print_unbr(unsigned int u);
int		ft_print_hex(unsigned long x, char *base);

#endif
