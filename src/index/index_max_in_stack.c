/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_max_in_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:39:50 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 19:26:25 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_max_in_stack(t_stack *stack)
{
	int	max;

	max = -1;
	if (stack)
	{
		max = stack->index;
		while (stack)
		{
			if (stack->index > max)
				max = stack->index;
			stack = stack->next;
		}
	}
	return (max);
}
