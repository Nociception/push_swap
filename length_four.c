/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:10:17 by nstoutze          #+#    #+#             */
/*   Updated: 2023/01/30 19:22:44 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sorted_final_stack(t_stack *A)
{
	int	i;
	int	ii_max;

	if (A)
	{
		i = 0;
		ii_max = A->initial_index_max + 1;
		// ligne trop longue
		while (++i <= ii_max && A->next && (A->index + 1)%ii_max == A->next->index)
			A = A->next;
		if (i == ii_max && !(A->next))
			return (1);
	}
	return (0);
}

void	set_sorted_final_stack_ontop(t_stack **A)
{
	if (*A && sorted_final_stack(*A))
		extract_target_ontop(0, A);
}

int	sorted_final_stack_ontop(t_stack *A)
{
	return (A && sorted_final_stack(A) && !(top_stack(A)->index));
}

static	void	moves_tb_direct_neighbors(t_stack **A)
{
	if (top_bottom_in_order(*A))
		rotate_a(A);
	else
	{
		reverserotate_a(A);
		swap_a(A);
	}
}

static	void	moves_ts_direct_neighbors(t_stack **A)
{
	if (top_second_in_order(*A))
		ra_twice_if_necessary(A);
	else
		swap_a(A);
}

void	algo_four(t_stack **A)
{
	if (*A)
	{
		while (!sorted_final_stack(*A))
		{
			if (top_second_dneighbors(*A))
				moves_ts_direct_neighbors(A);
			else if (top_bottom_dneighbors(*A))
				moves_tb_direct_neighbors(A);
			else
				rotate_a(A);
		}
		set_sorted_final_stack_ontop(A);
	}
}
