/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:22:19 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 20:06:05 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	pf_putnbrbase(unsigned long long nb, char *base)
{
	if (nb >= 0 && nb < (unsigned long long)pf_strlen(base))
		pf_putchar(base[nb]);
	else if (nb < 0)
	{
		pf_putchar('-');
		pf_putnbrbase(nb * -1, base);
	}
	else
	{
		pf_putnbrbase(nb / pf_strlen(base), base);
		pf_putnbrbase(nb % pf_strlen(base), base);
	}
}

void	pf_putnbr_ptr(unsigned long long nb, char *base)
{
	if (checkbase(base))
		pf_putnbrbase(nb, base);
}
