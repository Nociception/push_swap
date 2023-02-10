/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:51:43 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/10 23:29:35 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	top = NULL;
	second = NULL;
	bottom = NULL;
	if (*stack)
	{
		top = top_stack(*stack);
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

void	rotate_a(t_stack **a, t_stack *b)
{
	t_stack	*index_zero;

	if (*a && (*a)->next)
	{
		rotate(a);
		printf("ra\n");
		index_zero = index_stack(*a, b, 0);
		add_back_move(index_zero->move, 'r', 'a', ' ');
	}

}

void	rotate_b(t_stack *a, t_stack **b)
{
	t_stack	*index_zero;

	if (*b && (*b)->next)
	{
		rotate(b);
		printf("rb\n");
		index_zero = index_stack(a, *b, 0);
		add_back_move(index_zero->move, 'r', 'b', ' ');
	}

}

void	rotate_both(t_stack **a, t_stack **b)
{
	t_stack *index_zero;

	if (*a && (*a)->next && *b && (*b)->next)
	{
		printf("rr\n");
		rotate(a);
		rotate(b);
		index_zero = index_stack(*a, *b, 0);
		add_back_move(index_zero->move, 'r', 'r', ' ');
	}
}