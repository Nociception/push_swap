/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:43:56 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/10 23:34:02 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_fct(t_stack **first, t_stack **second, t_stack **third)
{
	(*third) = (*second)->next;
	(*third)->precedent = *first;
	(*first)->next = *third;
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = NULL;
	second = NULL;
	third = NULL;
	if (*stack)
	{
		first = top_stack(*stack);
		if (first->next)
		{
			second = first->next;
			first->next = NULL;
			if (second->next)
				third_fct(&first, &second, &third);
			first->precedent = second;
			second->precedent = NULL;
			second->next = first;
			*stack = second;
		}
	}
}

void	swap_a(t_stack **a, t_stack *b)
{
	t_stack	*index_zero;

	if (*a && (*a)->next)
	{
		swap(a);
		printf("sa\n");
		index_zero = index_stack(*a, b, 0);
		add_back_move(index_zero->move, 's', 'a', ' ');
	}

}

void	swap_b(t_stack *a, t_stack **b)
{
	t_stack	*index_zero;

	if (*b && (*b)->next)
	{
		swap(b);
		printf("sb\n");
		index_zero = index_stack(a, *b, 0);
		add_back_move(index_zero->move, 's', 'b', ' ');
	}

}

void	swap_both(t_stack **a, t_stack **b)
{
	t_stack *index_zero;

	if (*a && (*a)->next && *b && (*b)->next)
	{
		printf("ss\n");
		swap(a);
		swap(b);
		index_zero = index_stack(*a, *b, 0);
		add_back_move(index_zero->move, 's', 's', ' ');
	}
}
