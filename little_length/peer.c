/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peer.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:28:50 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:47:27 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	peer_in_order(t_stack *a, int x, int y)
{
	int	index_max;
	int	range;

	if (a)
	{
		index_max = a->index_max;
		if ((x == 0 && y == index_max) || (x == index_max && y == 0))
			return (1);
		range = abs_val(x - y);
		if (range == 1)
			return (1);
	}
	return (0);
}

int	peer_peer_peer(t_stack *a)
{
	int	first_peer;
	int	second_peer;
	int	third_peer;
	int	second_third;
	int	fourth_fifth;

	if (len_stack(a) == 6)
	{
		a = top_stack(a);
		first_peer = peer_in_order(a, a->index, a->next->index);
		a = a->next->next;
		second_third = peer_in_order(a, a->precedent->index, a->index);
		second_peer = peer_in_order(a, a->index, a->next->index);
		a = a->next->next;
		fourth_fifth = peer_in_order(a, a->precedent->index, a->index);
		third_peer = peer_in_order(a, a->index, a->next->index);
		return (first_peer && second_peer && third_peer
			&& !second_third && !fourth_fifth);
	}
	return (0);
}

void	moves_ppp(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next)
	{
		push_b(a, b);
		push_b(a, b);
		rotate_a(a);
		rotate_a(a);
		push_a(a, b);
		push_a(a, b);
	}
}
