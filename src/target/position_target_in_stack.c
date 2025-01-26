/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_target_in_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:41:37 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 19:27:33 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_target_in_stack(int target, t_stack *stack)
{
	int	position;

	if (stack)
	{
		stack = top_stack(stack);
		position = 0;
		while (stack)
		{
			if (stack->index == target)
				return (position);
			position++;
			stack = stack->next;
		}
	}
	return (-1);
}
