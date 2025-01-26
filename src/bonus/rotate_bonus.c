/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:15:40 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:15:42 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	real_rotate(t_stack **top, t_stack **second, t_stack **bottom)
{
	(*bottom)->next = *top;
	(*top)->precedent = *bottom;
	(*top)->next = NULL;
	(*second)->precedent = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*second;
	t_stack	*bottom;

	*stack = top_stack(*stack);
	top = *stack;
	second = NULL;
	bottom = NULL;
	if (len_stack(*stack) == 2)
		swap(stack);
	else if (*stack)
	{
		if ((*stack)->next)
		{
			second = (*stack)->next;
			if (!(second->next))
				rotate(stack);
			else
			{
				bottom = bottom_stack(*stack);
				real_rotate(&top, &second, &bottom);
				*stack = second;
			}
		}
	}
}

void	rotate_a(t_stack **a)
{
	if (*a && (*a)->next)
		rotate(a);
}

void	rotate_b(t_stack **b)
{
	if (*b && (*b)->next)
		rotate(b);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		rotate(a);
		rotate(b);
	}
}
