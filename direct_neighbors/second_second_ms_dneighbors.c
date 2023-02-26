/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_second_ms_dneighbors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:53:21 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/21 19:24:13 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	second_second_ms_dneighbors(t_stack *a, t_stack *b)
{
	if (a && a->next && b && b->next)
	{
		a = (top_stack(a))->next;
		b = (top_stack(b))->next;
		return (direct_neighbors(a->index, b->index, a->index_max));
	}
	return (0);
}

void	moves_ss_ms_dneighbors(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		*a = top_stack(*a);
		*b = top_stack(*b);
		swap_both(a, b);
	}
}
