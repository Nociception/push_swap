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

int	best_priority_choice(int *prio, int *sec, int len_sec, t_stacks *stacks)
{
	t_stack	*stack_first;
	t_stack	*stack_second;
	int score_first;
	int score_second;

	if (prio[1] < 0)
		return (prio [0]);
	stack_first = which_stack(prio[0], stacks->a, stacks->b);
	stack_second = which_stack(prio[1], stacks->a, stacks->b);
	score_first = harvest_score_from_top(prio[0], sec, len_sec, stack_first);
	score_second = harvest_score_from_top(prio[1], sec, len_sec, stack_second);
	if (score_first > score_second)
		return (prio[1]);
	return (prio[0]);
}

void	extract_prio_from_b_part_two(int bc, t_stacks *st, int *sec, int len_s)
{
	if (pos_index_in_stack(bc, st->b) <= (len_stack(st->b) / 2))
	{
		while (top_stack(st->b)->index != bc)
		{
			if (is_nb_in_array(top_stack(st->b)->index, sec, len_s))
				push_a(&(st->a), &(st->b));
			else
				rotate_b(st->a, &(st->b));
		}
	}
	else
	{
		while (top_stack(st->b)->index != bc)
		{
			reverserotate_b(st->a, &(st->b));
			if (is_nb_in_array(top_stack(st->b)->index, sec, len_s))
				push_a(&(st->a), &(st->b));
		}
	}
}

void	extract_priority_part_two(int bc, t_stacks *st, int *sec, int len_sec)
{
	//printf("eppt : Entree\n");
	if (target_in_stack(bc, st->b))
	{
		//printf("eppt : entre dans le if\n");
		extract_prio_from_b_part_two(bc, st, sec, len_sec);
		push_a(&(st->a), &(st->b));
	}
	else if (target_in_stack(bc, st->a))
	{
		//printf("eppt : entre dans le else if\n");
		while (top_stack(st->a)->index != bc)
			push_b(&(st)->a, &(st)->b);
	}
}

void	update_sent_priority_part_two(int best_choice, int *priority)
{
	if (priority[0] && priority[1])
	{
		if (best_choice == priority[0])
			priority[0] *= -1;
		else if (best_choice == priority[1])
			priority[1] *= -1;
	}
}

void	plug_priority(int best_choice, t_stack **a, t_stack **b, int *priority)
{
	if (priority[1] < 0)
	{
		reverserotate_a(a, *b);
		swap_a(a, *b);
		rotate_a(a, *b);
	}
	rotate_a(a, *b);
	update_sent_priority_part_two(best_choice, priority);
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

void	update_priority_from_secondary(int *prio, int *sec, int *nb_shift)
{
	if (prio[0] < 0 && prio[1] < 0)
	{
		prio[0] = sec[0];
		prio[1] = sec[1];
		*nb_shift = 2;
	}
	else if (prio[0] < 0 && prio[1] > 0)
	{
		prio[0] = prio[1];
		prio[1] = sec[0];
		*nb_shift = 1;
	}
}

void	lists_update_part_two(int *priority, int *secondary, int len_sec)
{
	printf("list_update_part_two : Entree\n");
	int	nb_shift;

	update_priority_from_secondary(priority, secondary, &nb_shift);
	shift_secondary(secondary, nb_shift, len_sec);
	printf("list_update_part_two : Fin\n");
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

#include <unistd.h>
void    part_two(t_stack **a, t_stack **b, t_stack *s)
{
	printf("part_two : Entree\n");
	show_abs(*a, *b, s, len_stack(s));
	// Durant cette partie, les secondary ne transitent qu'entre les tops de a et de b
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
		printf("part_two(boucle): debut iteration\n");
		//show_stack(*a);
		//show_stack(*b);
		//show_abs(*a, *b, s, len_stack(s));

		//show_abs(stacks->a, stacks->b, s, len_stack(s));
		printf("part_two(boucle): show_abs passe\n");
		//printf("part_two(boucle): best_choice proche ; affichage des parametres :\n");
		//printf("part_two(boucle): priority[0] = ")
        best_choice = best_priority_choice(priority, sec, len_sec, stacks);
		printf("part_two(boucle): best_choice defini = %d\n", best_choice);
		//show_abs(*a, *b, s, len_stack(s));
		//show_abs(stacks->a, stacks->b, s, len_stack(s));
        extract_priority_part_two(best_choice, stacks, sec, len_sec);
		/*
		plutot que de grouper a et b dans stacks, grouper sec et len_sec dans
		une structure, de maniere a ne retoucher que part_two, et non TOUT le code
		*/
		printf("part_two(boucle): best_choice extrait\n");
		//show_abs(*a, *b, s, len_stack(s));
		//show_abs(stacks->a, stacks->b, s, len_stack(s));
        plug_priority(best_choice, &(stacks->a), &(stacks->b), priority);
		printf("part_two(boucle): plug_priority DONE\n");
		//show_abs(*a, *b, s, len_stack(s));
		show_abs(stacks->a, stacks->b, s, len_stack(s));
		//printf("part_two(boucle): priority[0] = %d ; priority[1] = %d\n", priority[0], priority[1]);
        lists_update_part_two(priority, sec, len_sec);
		printf("part_two(boucle): priority[0] = %d ; priority[1] = %d\n", priority[0], priority[1]);
		printf("part_two(boucle): list_update_part_two DONE\n");
		//show_abs(*a, *b, s, len_stack(s));
		//show_abs(stacks->a, stacks->b, s, len_stack(s));
		printf("part_two(boucle): Fin de l'iteration\n");
		sleep(1);
    }
	printf("part_two : Fin\n");
}