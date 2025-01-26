/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge_after_twelve.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:03:51 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 14:52:30 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	purge_after_twelve(t_stack **a, t_stack **b)
{
	int	mid;
	int	part;
	int	c;
	int	min;
	int	max;

	mid = (*a)->index_max / 2;
	set_part_value(*a, &part);
	c = 0;
	*a = top_stack(*a);
	while (!only_twelve_first(*a))
	{
		c++;
		min = mid - (part * c);
		max = mid + (part * c);
		if (min <= 11)
			min = 12;
		while (range_in_stack(*a, min, max))
			presort(a, b, min, max);
	}
}

/*
void	purge_after_twelve(t_stack **a, t_stack **b)
{
	int	mid;
	int	part;
	int	c;
	int	min;
	int	max;

	
	mid = len_stack(*a) / 2;
	set_part_value(*a, &part);
	//printf("pat : mid = %d, part = %d\n", mid, part);
	c = 0;
	*a = top_stack(*a);
	while (!only_twelve_first(*a))
	{
		//printf("pat(boucle) : debut iteration\n");
		c++;
		min = mid - (part * c);
		max = mid + (part * c);
		if (min <= 11)
			min = 12;
		//printf("pat(boucle) : parametres set\n");
		//printf("pat(boucle) : c = %d, min = %d,
		max = %d, part = %d\n", c, min, max, part);
		while (range_in_stack(*a, min, max))
		{
			//printf("pat(boucle;boucle) : debut iteration\n");
			*a = top_stack(*a);
			if ((*a)->index >= min && (*a)->index <= max)
			{
				//printf("pat(boucle;boucle;if) : entree\n");
				push_b(a, b);
				*b = top_stack(*b);
				if ((*b)->index >= mid + 1 && (*b)->index <= max)
					rotate_b(*a, b);
			}
			else
			{
				//printf("pat(boucle;boucle;else) : entree\n");
				rotate_a(a, *b);
			}
		}
	}
}
*/