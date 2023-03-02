/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:15:24 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:50 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (*b)
		push(b, a);
}

void	push_b(t_stack **a, t_stack **b)
{
	if (*a)
		push(a, b);
}
