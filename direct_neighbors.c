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

int	both_tops_dneighbors(t_stack *A, t_stack *B)
{
	if (A && B)
	{
		A = top_stack(A);
		B = top_stack(B);
		return (direct_neighbors(A->index, B->index, A->index_max));
	}
	return (0);
}

int	top_second_dneighbors(t_stack *A)
{
	if (A && A->next)
	{
		A = top_stack(A);
		return (direct_neighbors(A->index, A->next->index, A->index_max));
	}
	return (0);
}

int	top_bottom_dneighbors(t_stack *A)
{
	int	index_bottom;

	index_bottom = 0;
	if (A && A->next)
	{
		A = top_stack(A);
		index_bottom = (bottom_stack(A))->index;
		return (direct_neighbors(A->index, index_bottom, A->index_max));
	}
	return (0);
}

int	both_tops_in_order(t_stack *A, t_stack *B)
{
	int	mod;

	if (A && B)
	{
		mod = A->index_max + 1;
		A = top_stack(A);
		B = top_stack(B);
		return ((B->index + 1)%mod == A->index);
	}
	return (0);
}

int	top_second_in_order(t_stack *A)
{
	int	mod;

	if (A && A->next)
	{
		A = top_stack(A);
		mod = A->index_max + 1;
		return ((A->index + 1) % mod == A->next->index);
	}
	return (0);
}

int	top_bottom_in_order(t_stack *A)
{
	int	mod;
	t_stack *top;
	t_stack *bottom;

	if (A && A->next)
	{

		mod = A->index_max + 1;
		top = top_stack(A);
		bottom = bottom_stack(A);
		return ((bottom->index + 1) % mod == top->index);
	}
	return (0);
}

