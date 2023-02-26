/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:14:47 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:59:01 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	checkbase(char *base)
{
	unsigned int	i;
	unsigned int	b;

	b = 0;
	i = 0;
	if (pf_strlen(base) <= 1)
		return (0);
	while (base[b])
	{
		i = b + 1;
		if (base[b] == '+' || base[b] == '-')
			return (0);
		while (base[i])
		{
			if (base[i] == base[b])
				return (0);
			i++;
		}
		b++;
	}
	return (1);
}
