/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_index_in_stack_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:14:43 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:31 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
