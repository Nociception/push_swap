/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:24:33 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:59:02 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_p(va_list arg)
{
	unsigned long long	n;
	int					addlen;

	n = va_arg(arg, unsigned long long);
	addlen = 2;
	pf_putstr("0x");
	if (!n)
	{
		pf_putchar('0');
		return (3);
	}
	pf_putnbr_ptr(n, "0123456789abcdef");
	return (pf_unslololen(n) + addlen);
}
