/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_tops_dneighbors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:50:15 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/21 19:20:49 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	both_tops_dneighbors(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		a = top_stack(a);
		b = top_stack(b);
		return (direct_neighbors(a->index, b->index, a->index_max));
	}
	return (0);
}

void	moves_tt_dneighbors(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		push_a(a, b);
		if (!top_second_in_order(*a))
			swap_a(a, *b);
		ra_twice_if_necessary(a, *b);
	}
}
