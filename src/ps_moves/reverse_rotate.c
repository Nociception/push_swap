/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:50:14 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 20:05:34 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverserotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*before_bottom;
	t_stack	*bottom;

	top = NULL;
	before_bottom = NULL;
	bottom = NULL;
	if (*stack)
	{
		top = top_stack(*stack);
		if (len_stack(*stack) > 2)
		{
			bottom = bottom_stack(*stack);
			before_bottom = bottom->precedent;
			top->precedent = bottom;
			bottom->precedent = NULL;
			bottom->next = top;
			before_bottom->next = NULL;
			*stack = bottom;
		}
		else if (len_stack(*stack) == 2)
			swap(stack);
	}
}

void	reverserotate_a(t_stack **a)
{
	if (*a && (*a)->next)
	{
		reverserotate(a);
		ft_printf("rra\n");
	}
}

void	reverserotate_b(t_stack **b)
{
	if (*b && (*b)->next)
	{
		reverserotate(b);
		ft_printf("rrb\n");
	}
}

void	reverserotate_both(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		ft_printf("rrr\n");
		reverserotate(a);
		reverserotate(b);
	}
}
