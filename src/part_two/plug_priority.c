/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plug_priority.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:01:12 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:51:33 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	second_before_first_moves(t_stack **a)
{
	reverserotate_a(a);
	swap_a(a);
	rotate_a(a);
	rotate_a(a);
}

void	plug_priority(t_stack **a, t_stack **b, int *priority, int *threshold)
{
	if (top_stack(*a)->index == priority[0])
	{
		if (bottom_stack(*a)->index != -priority[1])
			rotate_a(a);
		else
			second_before_first_moves(a);
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
		rotate_a(a);
		priority[1] *= -1;
	}
}
