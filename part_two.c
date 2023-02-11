#include "push_swap.h"

void	initialize_priority(int *priority, t_stack *a, t_stack *b)
{
	int bottom_a;

	if (len_stack(b) >= 2)
	{
		bottom_a = bottom_stack(a)->index;
		priority[0] = bottom_a + 1;
		priority[1] = priority[0] + 1;
	}
}


int *new_sec_part_two(t_stack *b, int divider, int *len_sec)
{
	printf("new_sec_part_two : Entree\n");
	int	range;
	int	len_secondary;
	int	*secondary;
	int	i;
	
	i = -1;
	range = index_max_in_stack(b) - index_min_in_stack(b) - 2;
	if (range <= 0)
		return (NULL);
	else if (range < 20)
		len_secondary = range;
	else
		len_secondary = range / divider;
	secondary = (int *)malloc(sizeof(int) * (len_secondary + 1));
	*len_sec = len_secondary;
	while (++i < len_secondary)
		secondary[i] = 0;
	printf("new_sec_part_two : Return imminent\n");
	return (secondary);
}


void	first_fill_sec(int *secondary, int len_secondary, int start, int end)
{
	int	i;

	i = -1;
	while (start < end && ++i < len_secondary)
	{
		secondary[i] = start;
		start++;
	}
}


void	show_sec(int *secondary, int len_secondary)
{
	int	i;

	printf("show_secondary ; here are the %d indexes :\n", len_secondary);
	i = -1;
	while (++i < len_secondary)
		printf("%d\n", secondary[i]);
	printf("show_secondary : end of printing\n");
}
/*------------------------FONCTIONNEL---------------------------------*/

t_stack	*which_stack(int target, t_stack *a, t_stack *b)
{
	if (target_in_stack(target, a))
		return (a);
	return (b);
}



int	harvest_score_from_top(int prio, int *secondary, int len_sec, t_stack *stack)
{
	int	score;

	score = 0;
	stack = top_stack(stack);
	while (stack && stack->index != prio)
	{
		if (is_nb_in_array(stack->index, secondary, len_sec))
			score++;
		else
			score += 2;
		stack = stack->next;
	}
	return (score);
}

int	best_priority_choice(int *priority, int *secondary, int len_sec, t_stacks *stacks)
{
	t_stack	*stack_first;
	t_stack	*stack_second;
	int score_first;
	int score_second;

	if (priority[1] < 0)
		return (priority [1]);
	stack_first = which_stack(priority[0], stacks->a, stacks->b);
	stack_second = which_stack(priority[1], stacks->a, stacks->b);
	score_first = harvest_score_from_top(priority[0], secondary, len_sec, stack_first);
	score_second = harvest_score_from_top(priority[1], secondary, len_sec, stack_second);
	if (score_first > score_second)
		return (priority[1]);
	return (priority[0]);
}

void	extract_priority_ontop_part_two(int best_choice, t_stack **a, t_stack **b)
// avoir s'il est possible de la declarer en static pour raccourcir la ligne
{
	if (bottom_stack(*b)->index == best_choice)
		rotate_b(*a, b);
	else if (target_in_stack(best_choice, *a))
	{
		while ((*a)->index != best_choice)
		{
			*a = top_stack(*a);
			push_b(a, b);
		}
	}
	else if (target_in_stack(best_choice, *b))
	{
		while ((*b)->index != best_choice)
		{
			*b = top_stack(*b);
			push_a(a, b);
		}
	}
}

void	update_priority_part_two(int best_choice, int *priority)
{
	if (priority[0] && priority[1])
	{
		if (best_choice == priority[0])
			priority[0] *= -1;
		else if (best_choice == priority[1])
			priority[1] *= -1;
	}
}

void	send_and_plug_priority(int best_choice, t_stack **a, t_stack **b, int *priority)
// ligne trop longue
{
	if (*a && *b)
	{
		if (top_stack(*a)->index == best_choice)
			rotate_a(a, *b);
		else if (top_stack(*b)->index == best_choice)
		{
			push_a(a, b);
			rotate_a(a, *b);
		}
	}
	update_priority_part_two(best_choice, priority);
}

void	shift_secondary(int *secondary, int nb_shift, int len_sec)
{
	int	i;
	int	stop;

	i = -1;
	stop = len_sec - nb_shift;
	while (++i < stop)
		secondary[i] = secondary[i + nb_shift];
	while (stop < len_sec)
	{
		secondary[stop] = 0;
		stop++;
	}
}

void	update_priority(int *priority, int *secondary, int *nb_shift)
{
	if (priority[0] < 0 && priority[1] < 0)
	{
		priority[0] = secondary[0];
		priority[1] = secondary[1];
		*nb_shift = 2;
	}
	else if (priority[0] < 0 && priority[1] > 0)
	{
		priority[0] = priority[1];
		priority[1] = secondary[0];
		*nb_shift = 1;
	}
}

void	lists_update_part_two(int *priority, int *secondary, int len_sec)
{
	int	nb_shift;

	update_priority(priority, secondary, &nb_shift);
	shift_secondary(secondary, nb_shift, len_sec);
}

t_stacks	*new_stacks(t_stack *a, t_stack *b)
{
	t_stacks	*stacks;
	stacks = malloc(sizeof(*stacks));
	if (!stacks)
		return (NULL);
	stacks->a = a;
	stacks->b = b;
	return (stacks);
}

void    part_two(t_stack **a, t_stack **b, t_stack *s)
{
	printf("part_two : Entree\n");
	show_abs(*a, *b, s, len_stack(s));
	// Durant cette partie, les secondary ne transitent qu'entre les top de a et de b
    int priority[2];
    int *sec;
	int	len_sec;
    int best_choice;
	t_stacks	*stacks;

	stacks = new_stacks(*a, *b);
    initialize_priority(priority, *a, *b);
	//printf("part_two : priority[0] = %d ; priority[1] = %d\n", priority[0], priority[1]);
    sec = new_sec_part_two(*b, 4, &len_sec); // divider a ajuster ; comment ?
	//show_sec(sec, len_sec);
	printf("part_two : sec genere\n");
	first_fill_sec(sec, len_sec, priority[1] + 1, index_max_in_stack(*b));
	printf("part_two : sec rempli\n");
	show_sec(sec, len_sec);
	printf("part_two : boucle imminente\n");
    while (priority[0])
    {
		printf("part_two (boucle): debut iteration\n");
        best_choice = best_priority_choice(priority, sec, len_sec, stacks);
		printf("part_two (boucle): best_choice defini\n");
        extract_priority_ontop_part_two(best_choice, a, b);
		printf("part_two (boucle): best_choice extrait\n");
        send_and_plug_priority(best_choice, a, b, priority);
        lists_update_part_two(priority, sec, len_sec);
    }
	printf("part_two : Fin\n");
}