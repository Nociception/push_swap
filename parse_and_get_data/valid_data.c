/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:45:50 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 20:10:33 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	valid_data(int len, char *av[])
{
	int	i;
	int	shift;

	i = -1;
	if (len < 0)
	{
		shift = 0;
		len = -len;
	}
	else
		shift = 1;
	while (++i < len)
	{
		if (!ft_atoi_push_swap(av[i + shift]))
			return (0);
	}
	return (1);
}
