#include "push_swap.h"

int	only_twelve_first(t_stack *a)
{
	a = top_stack(a);
	while (a)
	{
		if (a->index >= 12)
			return (0);
		a = a->next;
	}
	return (1);
}

int	stargets_in_b(t_stack *b, int mean_left)
{
	while (b)
	{
		if (b->index <= mean_left)
			return (1);
		b = b->next;
	}
	return (0);
}

void purge_after_twelve(t_stack **a, t_stack **b)
{
	printf("purge_after_twelve : Entree\n");
	//le segfault est a trouver ici
	int	mean_left;

	mean_left = mean_two_positive_numbers(12, (*a)->initial_index_max);
	*a = top_stack(*a);
	*b = top_stack(*b);
	while (!only_twelve_first(*a))
	{
		if ((*a)->index >= 12)
		{
			push_b(a, b);
			if ((*b)->index > mean_left && stargets_in_b(*b, mean_left))
			{
				if ((*a)->index <= 11)
					rotate_both(a, b);
				else
					rotate_b(*a, b);
			}
		}
		else
			rotate_a(a, *b);
	}
}

int	only_three_to_eight(t_stack *a)
{
	a = top_stack(a);
	while (a)
	{
		if (a->index <= 2 || a->index >= 9)
			return (0);
		a = a->next;
	}
	return (1);
}

int	only_six_seven_eight(t_stack *a)
{
	a = top_stack(a);
	while (a)
	{
		if (a->index <= 5 || a->index >= 9)
			return (0);
		a = a->next;
	}
	return (1);
}

void    last_purge(t_stack **a, t_stack **b)
{
	printf("last_purge : Entree\n");
	*a = top_stack(*a);
	while (!only_three_to_eight(*a))
	{
		if ((*a)->index >= 3 && (*a)->index <= 8)
			rotate_a(a, *b);
		else
			push_b(a, b);
	}
	while (!only_six_seven_eight(*a))
	{
		if ((*a)->index >= 6 && (*a)->index <= 8)
			rotate_a(a, *b);
		else
			push_b(a, b);
	}
}

void	decrease_indexes(t_stack *a)
{
	a = top_stack(a);
	while (a)
	{
		a->index -= 6;
		a = a->next;
	}
}

void	increase_indexes(t_stack *a)
{
	a = top_stack(a);
	while (a)
	{
		a->index += 6;
		a = a->next;
	}
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

void plug_nine_lucky(t_target *target, t_stack **a, t_stack **b, int *ht)
{
	if (target->stack == 'b')
	{
		if (target->destination == 'u')
		{
			extract_target_ontop(*ht, a, b);
			extract_target_ontop(target->index, a, b);
			push_a(a, b);
		}
		else if (target->destination == 'd')
		{
			extract_target_ontop(*ht, a, b);
			rotate_a(a, *b);
			extract_target_ontop(target->index, a, b);
			push_a(a, b);
			rotate_a(a, *b);
		}
	}
	else if (target->stack == 'a' && target->location == 'u')
	{

		extract_target_ontop(target->index, a, b);
		push_b(a, b);
		extract_target_ontop(*ht, a, b);
		push_a(a,b);
		if (target->destination == 'd')
			rotate_a(a, *b);
	}
	if (target->index > *ht)
		(*ht)++;
	else
		(*ht)--;
}

/*

	//tant que a n est pas ordonnee de 0 a 11
		//determiner la cible la plus proche
		l'extraire
		les produits d'extraction :
			si la cible choisie est dans le haut de b
				si la cible choisie est a destination du top de a
					prise rendue accessible
					produits au bottom de a
				si la cible choisie est a destination du bottom de a
					prise rendue accessible
					produits au top de a

		//	si la cible choisie est dans le haut de a
				si la cible choisie est a destination du top de a
					produits au bottom de a
					la cible est push sur b durant le deblayage,
						puis repush sur a une fois celui-ci termine
				si la cible choisie est a destination du bottom de a
					prise rendue accessible
					produits au top de b
			
		//	si la cible choisie est dans le bas de a
				si la cible choisie est a destination du top de a
					prise rendue accessible
					produits au top de b
				si la cible choisie est a destination du bottom de a
					produits au top de a
					la cible est push sur b durant le deblayage,
						puis repush sur a une fois celui-ci termine
	
}
*/

void    nine_lucky(t_stack **a, t_stack **b, t_stack *s)
{
	t_target	*btarget;
	int	head;
	int	tail;

	(void)s; // penser a virer les s de toute la part 1
	btarget = NULL;
	head = 6;
	tail = 8;
	while (head || tail < 11) 
	// ainsi, best target n'est appelee que si head > 0 et tail < 11
	{
		btarget = best_target(*a, *b, head, tail);
		if (btarget->index < head)
		{
			plug_nine_lucky(btarget, a, b, &head);
		}
		else
		{
			plug_nine_lucky(btarget, a, b, &tail);
		}
	}
}


void    part_one(t_stack **a, t_stack **b, t_stack *s)
{
	//printf("part_one : Entree\n");
    purge_after_twelve(a, b);
	last_purge(a, b);
    decrease_indexes(*a);
	algo_three(a, *b);
    increase_indexes(*a);
    nine_lucky(a, b, s);
}

/*------------------------FONCTIONNEL---------------------------------*/

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

/*

int *initialize_secondary(int *secondary, t_stack *b)
{

}

void    lists_update_part_two(int *prio[], int *sec[], t_stack *a, t_stack *b)
{

}
*/

void    part_two(t_stack **a, t_stack **b)
{
    int priority[2];
    //int *secondary;
    //int best_choice;

    initialize_priority(priority, *a, *b);
	printf("part_two : priority[0] = %d ; priority[1] = %d\n", priority[0], priority[1]);
	/*
    initialize_secondary(secondary,*b);
    while (priority[0] != -1)
    {
        best_choice = best_priority_choice(priority, secondary, *a, *b);
        extract_priority_ontop(best_choice, secondary, a, b);
        send_and_plug_priority(best_choice, a, b);
        lists_update(priority, secondary, *b);
        (&priority, &secondary, *a, *b);
    }
	*/
}
/*
void    part_three(t_stack **a, t_stack **b)
{

}

void    part_four(t_stack **a, t_stack **b)
{

}

void    part_five(t_stack **a, t_stack **b)
{

}
*/
void    algo_beyond_seven(t_stack **a, t_stack **b, t_stack *s)
{
	//printf("algo_beyond_seven : Entree\n");
	part_one(a, b, s);
    part_two(a, b);
	/*
    while (!sorted_final_stack(*a))
    {
        part_three(a, b);
        part_four(a, b);
        part_five(a, b);
    }
	*/
}
