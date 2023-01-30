#include "push_swap.h"

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