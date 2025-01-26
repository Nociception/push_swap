/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:57:21 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/11 23:57:21 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shortest_way_to_target(int target, t_stack *stack)
{
	int	way;
	int	len;

	way = 0;
	len = len_stack(stack);
	if (stack && target_in_stack(target, stack))
	{
		stack = top_stack(stack);
		while (stack)
		{
			if (stack->index == target)
			{
				if (way <= len / 2)
					return (way);
				return (way - (len + 1));
			}
			stack = stack->next;
			way++;
		}
	}
	return (0);
}

void	extraction(int nb_rotate, t_stack **a, t_stack **b, char stack)
{
	*a = top_stack(*a);
	*b = top_stack(*b);
	if (nb_rotate > 0)
	{
		while (--nb_rotate >= 0)
		{
			if (stack == 'a')
				rotate_a(a);
			else
				rotate_b(b);
		}
	}
	else if (nb_rotate < 0)
	{
		while (++nb_rotate < 0)
		{
			if (stack == 'a')
				reverserotate_a(a);
			else
				reverserotate_b(b);
		}
	}
}

void	extract_target_ontop(int target, t_stack **a, t_stack **b)
{
	int		nb_rotate;
	char	stack;

	if (target_in_stack(target, *a))
	{
		nb_rotate = shortest_way_to_target(target, *a);
		stack = 'a';
	}
	else
	{
		nb_rotate = shortest_way_to_target(target, *b);
		stack = 'b';
	}
	extraction(nb_rotate, a, b, stack);
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
