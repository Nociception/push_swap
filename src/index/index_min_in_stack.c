/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_min_in_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:38:57 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 19:26:28 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_min_in_stack(t_stack *stack)
{
	int	min;

	min = -1;
	if (stack)
	{
		min = stack->index;
		while (stack)
		{
			if (stack->index < min)
				min = stack->index;
			stack = stack->next;
		}
	}
	return (min);
}
