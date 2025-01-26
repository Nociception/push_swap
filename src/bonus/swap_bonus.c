/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:17:51 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:12:16 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	swap_a(t_stack **a)
{
	if (*a && (*a)->next)
		swap(a);
}

void	swap_b(t_stack **b)
{
	if (*b && (*b)->next)
		swap(b);
}

void	swap_both(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		swap(a);
		swap(b);
	}
}
