/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plug_priority.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:01:12 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 15:06:57 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	second_before_first_moves(t_stack **a, t_stack **b)
{
	reverserotate_a(a, *b);
	swap_a(a, *b);
	rotate_a(a, *b);
	rotate_a(a, *b);
}

void	plug_priority(t_stack **a, t_stack **b, int *priority, int *threshold)
{
	if (top_stack(*a)->index == priority[0])
	{
		if (bottom_stack(*a)->index != -priority[1])
			rotate_a(a, *b);
		else
			second_before_first_moves(a, b);
		if (len_stack(*b) >= 2)
		{
			priority[0] = bottom_stack(*a)->index + 1;
			priority[1] = priority[0] + 1;
			*threshold = define_threshold(*b, (*a)->index_max);
		}
		else if (len_stack(*b) == 1)
		{
			priority[0] = (*b)->index;
			*threshold = 0;
		}
	}
	else if (top_stack(*a)->index == priority[1])
	{
		rotate_a(a, *b);
		priority[1] *= -1;
	}
}
