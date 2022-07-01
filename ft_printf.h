/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psomjitr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:55:25 by psomjitr          #+#    #+#             */
/*   Updated: 2022/03/27 18:18:46 by psomjitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_print_format(va_list args, const char *s, int *ret);
void	ft_print_non_format(int s, int *ret);
void	ft_printf_c(int c, int *ret);
void	ft_printf_s(char *s, int *ret);
void	ft_printf_p(unsigned long long p, int *ret);
void	ft_put_p(unsigned long long p, int *ret);
void	ft_printf_di(int i, int *ret);
void	ft_printf_u(unsigned int i, int *ret);
void	ft_printf_x(unsigned long long p, const char *s, int *ret);
void	ft_put_lowerx(unsigned long long p, int *ret);
void	ft_put_upperx(unsigned long long p, int *ret);
void	ft_printf_mod(int *ret);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);

#endif
