/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:31:24 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:45:37 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 3 4 5

static void	three_for_five(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first == 4 && second == 3 && third == 5)
		swap_a(a);
	else if (first == 4 && second == 5 && third == 3)
		reverserotate_a(a);
	else if (first == 5 && second == 3 && third == 4)
		rotate_a(a);
	else if (first == 3 && second == 5 && third == 4)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first == 5 && second == 4 && third == 3)
	{
		swap_a(a);
		reverserotate_a(a);
	}
}

void	algo_six(t_stack **a, t_stack **b)
{
	extract_target_ontop(0, a, b);
	push_b(a, b);
	extract_target_ontop(1, a, b);
	push_b(a, b);
	extract_target_ontop(2, a, b);
	push_b(a, b);
	three_for_five(a);
	push_a(a, b);
	push_a(a, b);
	push_a(a, b);
}

/*
void	algo_six(t_stack **a, t_stack **b)
{
	if (*a)
	{
		while (!sorted_final_stack(*a))
		{
			if (peer_peer_peer(*a))
				moves_ppp(a, b);
			else if (both_tops_dneighbors(*a, *b))
				moves_tt_dneighbors(a, b);
			else if (top_second_dneighbors(*a))
				moves_ts_direct_neighbors(a, *b);
			else if (top_bottom_dneighbors(*a))
				moves_tb_direct_neighbors(a, *b);
			else if (top_second_ms_dneighbors(*a, *b))
				moves_ts_ms_dneighbors(*a, b);
			else if (second_second_ms_dneighbors(*a, *b))
				moves_ss_ms_dneighbors(a, b);
			else
				push_b(a, b);
		}
		set_sorted_final_stack_ontop(a, *b);
	}
}
*/
