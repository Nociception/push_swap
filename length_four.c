/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:10:17 by nstoutze          #+#    #+#             */
/*   Updated: 2023/01/29 22:47:07 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sorted_stack(t_stack *A)
{
	int	len;

	len = 0;
	if (A)
	{
		A = top_stack(A);
		len = len_stack(A);
		if (A->next)
		{
			while (A->next && (A->index + 1)%len == A->next->index)
				A = A->next;
			if (!(A->next))
				return (1);
			return (0);
		}
		return (0);
	}
	return (0);
}

int	target_in_stack(int target, t_stack *stack)
{
	if (stack)
	{
		while (stack)
		{
			if (stack->index == target)
				return (1);
			stack = stack->next;
		}
	}
	return (0);
}

int shortest_way_to_target(int target, t_stack *stack)
{
	int	way;

	way = 0;
	if (stack)
	{
		stack = top_stack(stack);
		while (stack)
		{
			if (stack->index == target)
			{
				if (way <= stack->index_max / 2)
					return (way);
				return (way - (stack->index_max + 1));
			}
			stack = stack->next;
			way++;
		}
	}
	return (2000);
}

void	extract_target_ontop(int target, t_stack **stack)
{
	int	nb_rotate;

	if (*stack && target_in_stack(target, *stack))
	{
		nb_rotate = shortest_way_to_target(target, *stack);
		if (nb_rotate > 0)
		{
			while (--nb_rotate >= 0)
			{
				if ((*stack)->a_or_b == 'A')
					rotate_a(stack);
				else
					rotate_b(stack);
			}
		}
		else if (nb_rotate < 0)
		{
			while (++nb_rotate <= 0)
			{
				if ((*stack)->a_or_b == 'A')
					reverserotate_a(stack);
				else
					reverserotate_b(stack);
			}
		}
	}
}
/*
void	set_sorted_stack_ontop(t_stack **A)
{
	void(A);
	return ;
}

int	sorted_stack_ontop(t_stack *A)
{

}

void	algo_four(t_stack **A)
{
	while (!stack_sorted(*A))
	{
		if (top_bottom_dneighbors(*A))
		{
			if (top_bottom_in_order(*A))
				rotate_a(A);
		}
		else if (first_second_dneighbors(*A))
		{
			if (first_second_in_order(*A))
			{
				rotate_a(A);
				rotate_a(A);
			}
			else
				swap_a(A);
		}
		else
			rotate_a(A);
	}
	set_sorted_stack_ontop(A);
}
*/