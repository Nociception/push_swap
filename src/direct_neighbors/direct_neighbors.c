/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_neighbors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:31:49 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 19:26:02 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	direct_neighbors(int i, int j, int index_max)
{
	int	range;

	if ((i == 0 && j == index_max) || (i == index_max && j == 0))
		return (1);
	range = abs_val(i - j);
	if (range == 1)
		return (1);
	return (0);
}
