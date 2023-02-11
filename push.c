/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:02:20 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/12 00:12:49 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **origin, t_stack **dest)
{
	t_stack	*top_origin;
	t_stack	*second_origin;
	t_stack	*top_dest;

	top_origin = NULL;
	second_origin = NULL;
	top_dest = NULL;
	if (*origin)
	{
		top_origin = top_stack(*origin);
		if ((*origin)->next)
			second_origin = (*origin)->next;
		*origin = second_origin;
		if (*origin && (*origin)->precedent)
			(*origin)->precedent = NULL;
		if (*dest)
		{
			top_dest = top_stack(*dest);
			top_dest->precedent = top_origin;
		}
		top_origin->next = top_dest;
		*dest = top_origin;
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*index_zero;

	if (*b)
	{
		printf("pa\n");
		push(b, a);
		*a = top_stack(*a);
		(*a)->a_or_b = 'a';
		index_zero = index_stack(*a, *b, 0);
		add_back_move(index_zero->move, 'p', 'a', ' ');
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*index_zero;

	if (*a)
	{
		printf("pb\n");
		push(a, b);
		*b = top_stack(*b);
		(*b)->a_or_b = 'b';
		index_zero = index_stack(*a, *b, 0);
		add_back_move(index_zero->move, 'p', 'b', ' ');
	}
}
