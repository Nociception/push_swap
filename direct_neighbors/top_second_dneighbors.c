/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_second_dneighbors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:51:17 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/21 19:21:09 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	top_second_dneighbors(t_stack *a)
{
	if (a && a->next)
	{
		a = top_stack(a);
		return (direct_neighbors(a->index, a->next->index, a->index_max));
	}
	return (0);
}

void	moves_ts_direct_neighbors(t_stack **a, t_stack *b)
{
	if (*a && (*a)->next)
	{
		if (!top_second_in_order(*a))
		{
			swap_a(a, b);
			if (both_tops_dneighbors(*a, b))
				return ;
		}
		ra_twice_if_necessary(a, b);
	}
}
