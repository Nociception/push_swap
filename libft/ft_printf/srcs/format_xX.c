/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:24:59 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:59:03 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_x(va_list arg)
{
	unsigned int	n;
	int				len;

	n = va_arg(arg, unsigned int);
	len = 0;
	pf_putnbr_base((long long)n, "0123456789abcdef");
	if (n < 0)
		len += 1;
	len += pf_intlen((long long)n, 'x');
	return (len);
}

int	format_upx(va_list arg)
{
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	pf_putnbr_base((long long)n, "0123456789ABCDEF");
	if (n < 0)
		return (pf_intlen((long long)n, 'X') + 1);
	else
		return (pf_intlen((long long)n, 'X'));
}
