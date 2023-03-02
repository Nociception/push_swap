/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:03:22 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:48:37 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	presort(t_stack **a, t_stack **b, int min, int max)
{
	int	mid;

	mid = (*a)->index_max / 2;
	*a = top_stack(*a);
	if ((*a)->index >= min && (*a)->index <= max)
	{
		push_b(a, b);
		*b = top_stack(*b);
		if ((*b)->index >= mid + 1 && (*b)->index <= max)
			rotate_b(b);
	}
	else
		rotate_a(a);
}
