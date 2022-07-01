/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psomjitr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:32:07 by psomjitr          #+#    #+#             */
/*   Updated: 2022/03/27 18:18:25 by psomjitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
			ft_print_format(args, ++s, &ret);
		else
			ft_print_non_format(*s, &ret);
		s++;
	}
	va_end(args);
	return (ret);
}

void	ft_print_format(va_list args, const char *s, int *ret)
{
	if (*s == 'c')
		ft_printf_c(va_arg(args, int), ret);
	else if (*s == 's')
		ft_printf_s(va_arg(args, char *), ret);
	else if (*s == 'p')
		ft_printf_p(va_arg(args, unsigned long long), ret);
	else if (*s == 'd' || *s == 'i')
		ft_printf_di(va_arg(args, int), ret);
	else if (*s == 'u')
		ft_printf_u(va_arg(args, unsigned int), ret);
	else if (*s == 'x' || *s == 'X')
		ft_printf_x(va_arg(args, unsigned int), s, ret);
	else if (*s == '%')
		ft_printf_mod(ret);
}

void	ft_print_non_format(int s, int *ret)
{
	*ret += write(1, &s, 1);
}
