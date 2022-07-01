/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_px.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psomjitr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:59:15 by psomjitr          #+#    #+#             */
/*   Updated: 2022/03/24 13:29:20 by psomjitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(unsigned long long p, int *ret)
{
	ft_printf_s("0x", ret);
	if (!p)
		ft_printf_c('0', ret);
	else
		ft_put_p(p, ret);
}

void	ft_put_p(unsigned long long p, int *ret)
{
	if (p > 15)
	{
		ft_put_p(p / 16, ret);
		ft_put_p(p % 16, ret);
	}
	else
	{
		if (p < 10)
			ft_printf_c(p + '0', ret);
		else
			ft_printf_c(p - 10 + 'a', ret);
	}
}

void	ft_printf_x(unsigned long long p, const char *s, int *ret)
{
	if (!p)
		ft_printf_c('0', ret);
	else
	{
		if (*s == 'x')
			ft_put_lowerx(p, ret);
		if (*s == 'X')
			ft_put_upperx(p, ret);
	}
}

void	ft_put_lowerx(unsigned long long p, int *ret)
{
	if (p > 15)
	{
		ft_put_lowerx(p / 16, ret);
		ft_put_lowerx(p % 16, ret);
	}
	else
	{
		if (p < 10)
			ft_printf_c(p + '0', ret);
		else
			ft_printf_c(p - 10 + 'a', ret);
	}
}

void	ft_put_upperx(unsigned long long p, int *ret)
{
	if (p > 15)
	{
		ft_put_upperx(p / 16, ret);
		ft_put_upperx(p % 16, ret);
	}
	else
	{
		if (p < 10)
			ft_printf_c(p + '0', ret);
		else
			ft_printf_c(p - 10 + 'A', ret);
	}
}
