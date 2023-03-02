/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:24:33 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/28 17:33:20 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_p(va_list arg)
{
	unsigned long long	n;
	int					addlen;

	n = va_arg(arg, unsigned long long);
	addlen = 2;
	ft_putstr_fd("0x", 1);
	if (!n)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	ft_putnbr_ptr(n, "0123456789abcdef");
	return (ft_unslololen(n) + addlen);
}
