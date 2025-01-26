/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_second_ms_dneighbors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:52:35 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:28:32 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_second_ms_dneighbors(t_stack *a, t_stack *b)
{
	if (a && b && b->next)
	{
		a = top_stack(a);
		b = (top_stack(b))->next;
		return (direct_neighbors(a->index, b->index, a->index_max));
	}
	return (0);
}

void	moves_ts_ms_dneighbors(t_stack **b)
{
	if (*b && (*b)->next)
	{
		*b = top_stack(*b);
		swap_b(b);
	}
}
