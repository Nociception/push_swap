/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_purge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:05:51 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:47:55 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	last_purge(t_stack **a, t_stack **b)
{
	*a = top_stack(*a);
	while (!only_three_to_eight(*a))
	{
		if ((*a)->index >= 3 && (*a)->index <= 8)
			rotate_a(a);
		else
			push_b(a, b);
	}
	while (!only_six_seven_eight(*a))
	{
		if ((*a)->index >= 6 && (*a)->index <= 8)
			rotate_a(a);
		else
			push_b(a, b);
	}
}
