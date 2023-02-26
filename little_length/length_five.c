/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:57:41 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/11 23:57:41 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	two_three_four(t_stack **a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first == 3 && second == 2 && third == 4)
		swap_a(a, b);
	else if (first == 3 && second == 4 && third == 2)
		reverserotate_a(a, b);
	else if (first == 4 && second == 2 && third == 3)
		rotate_a(a, b);
	else if (first == 2 && second == 4 && third == 3)
	{
		swap_a(a, b);
		rotate_a(a, b);
	}
	else if (first == 4 && second == 3 && third == 2)
	{
		swap_a(a, b);
		reverserotate_a(a, b);
	}
}

void	ra_twice_if_necessary(t_stack **a, t_stack *b)
{
	if (*a && (*a)->next)
	{
		rotate_a(a, b);
		if (!sorted_final_stack(*a))
			rotate_a(a, b);
	}
}

void	algo_five(t_stack **a, t_stack **b)
{
	extract_target_ontop(0, a, b);
	push_b(a, b);
	extract_target_ontop(1, a, b);
	push_b(a, b);
	two_three_four(a, *b);
	push_a(a, b);
	push_a(a, b);
	if (!top_second_in_order(*a))
		swap_a(a, *b);
}
