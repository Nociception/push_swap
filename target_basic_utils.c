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

void	get_target_location(int ht, t_target *target, t_stack *b)
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
		if (position_target_in_stack(target->index, b) <= len_stack(b))
			target->location = 'u';
		else
			target->location = 'd';
	}
}

void	intel_target(int ht, t_target *target, t_stack *a, t_stack *b)
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
	if (target_in_stack(target->index, a))
		target->stack = 'a';
	else
		target->stack = 'b';
	get_target_location(ht, target, b);
}

void	show_target_details(t_target *target)
{
	printf("target->destination = %c\n", target->destination);
	printf("target->index = %d\n",target->index);
	printf("target->location = %c\n",target->location);
	printf("target->stack = %c\n",target->stack);
}

int	stargets_in_b(t_stack *b, int mean_left)
{
	//printf("stargets_in_b : Entree\n");
	while (b)
	{
		if (b->index <= mean_left)
			return (1);
		b = b->next;
	}
	return (0);
}

t_target	*best_target(t_stack *a, t_stack *b, int head, int tail)
{
	t_target *above_head;
	t_target *below_tail;
	int	shortest_to_ah;
	int	shortest_to_bt;

	above_head = new_target();
	below_tail = new_target();
	shortest_to_ah = 0;
	shortest_to_bt = 0;
	intel_target(head, above_head, a, b);
	intel_target(tail, below_tail, a, b);
	if (target_in_stack(above_head->index, a))
		shortest_to_ah = shortest_way_to_target(above_head->index, a);
	else
		shortest_to_ah = shortest_way_to_target(above_head->index, b);
	if (target_in_stack(below_tail->index, a))
		shortest_to_bt = shortest_way_to_target(below_tail->index, a);
	else
		shortest_to_bt = shortest_way_to_target(below_tail->index, b);
	if (abs_val(shortest_to_ah) <= abs_val(shortest_to_bt))
		return (above_head);
	return (below_tail);
}