#include "push_swap.h"

void initialize_target(t_target *target)
{
	target->stack = 'n';
	target->index = -1;
	target->location = 'n';
	target->destination = 'n';
}

t_target *new_target(void)
{
    t_target *target;

    target = malloc(sizeof(*target));
    if (!target)
        return (NULL);
	initialize_target(target);
    return (target);
}

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

void	get_target_location(int ht, t_target *target, t_stack *B)
{
	if (target->stack == 'a')
	{
		if (target->index < ht)
			target->location = 'u';
		else
			target->location = 'd';
	}
	else if (target->stack == 'b')
	{
		if (position_target_in_stack(target->index, B) <= len_stack(B))
			target->location = 'u';
		else
			target->location = 'd';
	}
}

void	intel_target(int ht, t_target *target, t_stack *A, t_stack *B)
{
	if (ht <= 7)
	{
		target->index = ht - 1;
		target->destination = 'u';
	}
	else
	{
		target->index = ht + 1;
		target->destination = 'd';
	}
	if (target_in_stack(target->index, A))
		target->stack = 'a';
	else
		target->stack = 'b';
	get_target_location(ht, target, B);
}

void	show_target_details(t_target *target)
{
	printf("target->destination = %c\n", target->destination);
	printf("target->index = %d\n",target->index);
	printf("target->location = %c\n",target->location);
	printf("target->stack = %c\n",target->stack);
}