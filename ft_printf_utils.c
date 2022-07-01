/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psomjitr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:06:29 by psomjitr          #+#    #+#             */
/*   Updated: 2022/03/24 13:22:11 by psomjitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	find_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	find_len_u(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	find_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*s;
	int		n_cpy;

	n_cpy = n;
	len = find_len(n);
	s = (char *)malloc((len + 1) * sizeof(*s));
	if (!s)
		return (NULL);
	s += len;
	*s = '\0';
	if (n == 0)
		*--s = '0';
	while (n != 0)
	{
		*--s = '0' + find_abs(n % 10);
		n /= 10;
	}
	if (n_cpy < 0)
		*--s = '-';
	return (s);
}

char	*ft_itoa_u(unsigned int n)
{
	size_t	len;
	char	*s;

	len = find_len_u(n);
	s = (char *)malloc((len + 1) * sizeof(*s));
	if (!s)
		return (NULL);
	s += len;
	*s = '\0';
	if (n == 0)
		*--s = '0';
	while (n != 0)
	{
		*--s = '0' + find_abs(n % 10);
		n /= 10;
	}
	return (s);
}
