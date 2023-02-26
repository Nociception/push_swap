/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:45:16 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 20:05:50 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	pf_putnbrbase(long long nb, char *base)
{
	if (nb >= 0 && nb < (long long)pf_strlen(base))
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

void	pf_putnbr_base(long long nbr, char *base)
{
	if (checkbase(base))
		pf_putnbrbase((long long)nbr, base);
}
