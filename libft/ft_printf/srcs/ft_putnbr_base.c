/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:18:13 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/28 18:11:57 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putnbrbase(long long nb, char *base)
{
	if (nb >= 0 && nb < (long long)ft_strlen(base))
		ft_putchar_fd(base[nb], 1);
	else if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbrbase(nb * -1, base);
	}
	else
	{
		ft_putnbrbase(nb / ft_strlen(base), base);
		ft_putnbrbase(nb % ft_strlen(base), base);
	}
}

void	ft_putnbr_base(long long nbr, char *base)
{
	if (checkbase(base))
		ft_putnbrbase((long long)nbr, base);
}
