/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_bottom_dneighbors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:51:54 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:57:15 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_bottom_dneighbors(t_stack *a)
{
	int	index_bottom;

	index_bottom = 0;
	if (a && a->next)
	{
		a = top_stack(a);
		index_bottom = (bottom_stack(a))->index;
		return (direct_neighbors(a->index, index_bottom, a->index_max));
	}
	return (0);
}

void	moves_tb_direct_neighbors(t_stack **a)
{
	if (*a)
	{
		if (!top_bottom_in_order(*a))
		{
			reverserotate_a(a);
			swap_a(a);
			ra_twice_if_necessary(a);
		}
		rotate_a(a);
	}
}
