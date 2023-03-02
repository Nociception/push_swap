/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction_best_choice.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:09:07 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:51:59 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	extraction_from_top_a(t_stack **a, t_stack **b, int bc, int thresh)
{
	while (top_stack(*a)->index != bc)
	{
		push_b(a, b);
		if (top_stack(*b)->index > thresh)
			rotate_b(b);
	}
}

static void	extraction_from_top_b(t_stack **a, t_stack **b, int bc, int thresh)
{
	while (top_stack(*b)->index != bc)
	{
		if (top_stack(*b)->index <= thresh)
			push_a(a, b);
		else
			rotate_b(b);
	}
	push_a(a, b);
}

static void	extraction_from_bottom_b(t_stack **a, t_stack **b, int bc, int thr)
{
	while (bottom_stack(*b)->index != bc)
	{
		reverserotate_b(b);
		if (top_stack(*b)->index <= thr)
			push_a(a, b);
	}
	reverserotate_b(b);
	push_a(a, b);
}

void	extraction_best_choice(int bc, t_stack **a, t_stack **b, int threshold)
{
	if (target_in_stack(bc, *a))
	{
		*a = top_stack(*a);
		extraction_from_top_a(a, b, bc, threshold);
	}
	else if (target_in_stack(bc, *b))
	{
		*b = top_stack(*b);
		if (pos_index_in_stack(bc, *b) <= len_stack(*b) / 2)
			extraction_from_top_b(a, b, bc, threshold);
		else
			extraction_from_bottom_b(a, b, bc, threshold);
	}
}
