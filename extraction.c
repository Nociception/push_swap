#include "push_swap.h"

int shortest_way_to_target(int target, t_stack *stack)
{
	int	way;
	int len;

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
	if (nb_rotate > 0)
	{
		while (--nb_rotate >= 0)
		{
			if (stack == 'a')
				rotate_a(a, *b);
			else
				rotate_b(*a, b);
		}
	}
	else if (nb_rotate < 0)
	{
		while (++nb_rotate < 0) // ++nb_rotate <= 0 passe en ++nb_rotate < 0
		{
			if (stack == 'a')
				reverserotate_a(a, *b);
			else
				reverserotate_b(*a, b);
		}
	}
}

void	extract_target_ontop(int target, t_stack **a, t_stack **b)
{
	int	nb_rotate;
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

/*
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
			while (++nb_rotate < 0) // ++nb_rotate <= 0 passe en ++nb_rotate < 0
			{
				if ((*stack)->a_or_b == 'A')
					reverserotate_a(stack);
				else
					reverserotate_b(stack);
			}
		}
	}
}
*/
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
