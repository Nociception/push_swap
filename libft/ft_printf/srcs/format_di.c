/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:24:12 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:59:02 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_di(va_list arg)
{
	int	n;

	n = va_arg(arg, int);
	pf_putnbr_base((long long)n, "0123456789");
	if (n < 0)
		return (pf_intlen((long long)n, 'd') + 1);
	else
		return (pf_intlen((long long)n, 'd'));
}
