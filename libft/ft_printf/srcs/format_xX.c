/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:24:59 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/28 17:25:51 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_x(va_list arg)
{
	unsigned int	n;
	int				len;

	n = va_arg(arg, unsigned int);
	len = 0;
	ft_putnbr_base((long long)n, "0123456789abcdef");
	if (n < 0)
		len += 1;
	len += ft_intlen((long long)n, 'x');
	return (len);
}

int	format_upx(va_list arg)
{
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	ft_putnbr_base((long long)n, "0123456789ABCDEF");
	if (n < 0)
		return (ft_intlen((long long)n, 'X') + 1);
	else
		return (ft_intlen((long long)n, 'X'));
}
