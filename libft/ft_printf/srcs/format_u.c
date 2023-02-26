/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:24:45 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:59:03 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_u(va_list arg)
{
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	pf_putnbr_base((long long)n, "0123456789");
	return (pf_intlen((long long)n, 'd'));
}
