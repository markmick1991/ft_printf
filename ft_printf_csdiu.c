/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csdiu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psomjitr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:58:36 by psomjitr          #+#    #+#             */
/*   Updated: 2022/03/24 13:12:12 by psomjitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(int c, int *ret)
{
	*ret += write(1, &c, 1);
}

void	ft_printf_s(char *s, int *ret)
{
	if (!s)
		ft_printf_s("(null)", ret);
	else
		while (*s)
			*ret += write(1, s++, 1);
}

void	ft_printf_di(int i, int *ret)
{
	char	*temp;

	temp = ft_itoa(i);
	ft_printf_s(temp, ret);
	free(temp);
}

void	ft_printf_u(unsigned int i, int *ret)
{
	char	*temp;

	temp = ft_itoa_u(i);
	ft_printf_s(temp, ret);
	free(temp);
}

void	ft_printf_mod(int *ret)
{
	*ret += write(1, "%", 1);
}
