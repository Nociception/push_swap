/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_details.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:59:46 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/12 00:20:19 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack_backlinks(t_stack *stack)
{
	int		i;
	t_stack	*precedent;

	stack->precedent = NULL;
	if (len_stack(stack) == 1)
	{
		stack->precedent = NULL;
		stack->next = NULL;
		return ;
	}
	precedent = stack;
	i = -1;
	while (stack && ++i >= 0)
	{
		if (i)
		{
			stack->precedent = precedent;
			precedent = stack;
		}
		stack = stack->next;
	}
}

void	show_stack_details(t_stack *stack)
{
	printf("-------------\n");
	while (stack)
	{
		printf("stack->nb = %d  stack->index = %d\n", stack->nb, stack->index);
		printf("stack->index_max = %d\n", stack->index_max);
		stack = stack->next;
	}
	printf("-------------\n");
}
