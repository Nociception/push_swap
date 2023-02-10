/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_neighbors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:31:49 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/06 17:55:19 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	direct_neighbors(int i, int j, int index_max)
{
	int range;

	if ((i == 0 && j == index_max) || (i == index_max && j == 0))
		return (1);
	range = abs_val(i - j);
	if (range == 1)
		return (1);
	return (0);
}

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

int	top_second_dneighbors(t_stack *a)
{
	if (a && a->next)
	{
		a = top_stack(a);
		return (direct_neighbors(a->index, a->next->index, a->index_max));
	}
	return (0);
}

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

int	both_tops_in_order(t_stack *a, t_stack *b)
{
	int	mod;

	if (a && b)
	{
		mod = a->index_max + 1;
		a = top_stack(a);
		b = top_stack(b);
		return ((b->index + 1)%mod == a->index);
	}
	return (0);
}

int	top_second_in_order(t_stack *a)
{
	int	mod;

	if (a && a->next)
	{
		a = top_stack(a);
		mod = a->index_max + 1;
		return ((a->index + 1) % mod == a->next->index);
	}
	return (0);
}

int	top_bottom_in_order(t_stack *a)
{
	int	mod;
	t_stack *top;
	t_stack *bottom;

	if (a && a->next)
	{

		mod = a->index_max + 1;
		top = top_stack(a);
		bottom = bottom_stack(a);
		return ((bottom->index + 1) % mod == top->index);
	}
	return (0);
}

