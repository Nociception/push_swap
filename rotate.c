/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:51:43 by nstoutze          #+#    #+#             */
/*   Updated: 2023/01/28 21:54:44 by nstoutze         ###   ########.fr       */
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
				swap(stack);
			else
			{
				bottom = bottom_stack(*stack);
				real_rotate(&top, &second, &bottom);
				*stack = second;
			}
		}
	}
}

void	rotate_a(t_stack **A)
{
	printf("ra\n");
	rotate(A);
}

void	rotate_b(t_stack **B)
{
	printf("rb\n");
	rotate(B);
}

void	rotate_both(t_stack **A, t_stack **B)
{
	printf("rr\n");
	rotate(A);
	rotate(B);
}
