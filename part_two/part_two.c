/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:10:27 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 15:11:12 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	finisher(t_stack **a, t_stack **b)
{
	if (top_bottom_in_order(*a))
		rotate_a(a, *b);
	else if (top_bottom_dneighbors(*a))
	{
		reverserotate_a(a, *b);
		swap_a(a, *b);
		rotate_a(a, *b);
		rotate_a(a, *b);
	}
	if (bottom_stack(*a)->index == bottom_stack(*a)->precedent->index + 2)
	{
		extract_target_ontop(bottom_stack(*a)->precedent->index + 1, a, b);
		reverserotate_a(a, *b);
		push_a(a, b);
		rotate_a(a, *b);
		rotate_a(a, *b);
	}
	while (*b)
	{
		extract_target_ontop(bottom_stack(*a)->index + 1, a, b);
		if (top_stack(*b)->index == bottom_stack(*a)->index + 1)
			push_a(a, b);
		rotate_a(a, *b);
	}
}

void	part_two(t_stack **a, t_stack **b, t_stack *s)
{
	int	priority[2];
	int	threshold;
	int	best_choice;

	(void)s;
	initialize_priority(priority, *a, *b);
	threshold = define_threshold(*b, (*a)->index_max);
	while (priority[0] && threshold && len_stack(*b) >= 7)
	{
		best_choice = best_priority_choice(*a, *b, priority, threshold);
		extraction_best_choice(best_choice, a, b, threshold);
		plug_priority(a, b, priority, &threshold);
		threshold = define_threshold(*b, (*a)->index_max);
	}
	finisher(a, b);
	*a = top_stack(*a);
	if ((*a)->index != 0)
	{
		extract_target_ontop(0, a, b);
		push_b(a, b);
		*a = top_stack(*a);
		while ((*a)->index != 1)
			rotate_a(a, *b);
		push_a(a, b);
	}
}
