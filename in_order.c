/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:01:16 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/16 16:01:20 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	both_tops_in_order(t_stack *a, t_stack *b)
{
	int	mod;

	if (a && b)
	{
		mod = a->index_max + 1;
		a = top_stack(a);
		b = top_stack(b);
		return ((b->index + 1) % mod == a->index);
	}
	return (0);
}

int	top_second_in_order(t_stack *a)
{
	int	mod;

	if (a && a->next)
	{
		a = top_stack(a);
		mod = a->index_max + 1;
		return ((a->index + 1) % mod == a->next->index);
	}
	return (0);
}

int	top_bottom_in_order(t_stack *a)
{
	int		mod;
	t_stack	*top;
	t_stack	*bottom;

	if (a && a->next)
	{
		mod = a->index_max + 1;
		top = top_stack(a);
		bottom = bottom_stack(a);
		return ((bottom->index + 1) % mod == top->index);
	}
	return (0);
}
