/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_index_in_stack.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:37:22 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 19:26:20 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_element_index_in_stack(t_stack *stack, int index)
{
	stack = top_stack(stack);
	while (stack)
	{
		if (stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
