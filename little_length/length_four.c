/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:10:17 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/20 15:51:52 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	moves_tb_dneighbors(t_stack **a, t_stack *b)
{
	if (top_bottom_in_order(*a))
		rotate_a(a, b);
	else
	{
		reverserotate_a(a, b);
		swap_a(a, b);
	}
}

static void	moves_top_second_direct_neighbors(t_stack **a, t_stack *b)
{
	if (top_second_in_order(*a))
		ra_twice_if_necessary(a, b);
	else
		swap_a(a, b);
}

void	algo_four(t_stack **a, t_stack *b)
{
	if (*a)
	{
		while (!sorted_final_stack(*a))
		{
			if (top_second_dneighbors(*a))
				moves_top_second_direct_neighbors(a, b);
			else if (top_bottom_dneighbors(*a))
				moves_tb_dneighbors(a, b);
			else
				rotate_a(a, b);
		}
		set_sorted_final_stack_ontop(a, b);
	}
}
