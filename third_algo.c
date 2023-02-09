#include "push_swap.h"

int	only_twelve_first(t_stack *A)
{
	A = top_stack(A);
	while (A)
	{
		if (A->index >= 12)
			return (0);
		A = A->next;
	}
	return (1);
}

int	stargets_in_B(t_stack *B, int mean_left)
{
	while (B)
	{
		if (B->index <= mean_left)
			return (1);
		B = B->next;
	}
	return (0);
}

void purge_after_twelve(t_stack **A, t_stack **B)
{
	int	mean_left;

	mean_left = mean_two_positive_numbers(12, (*A)->initial_index_max);
	*A = top_stack(*A);
	*B = top_stack(*B);
	while (!only_twelve_first(*A))
	{
		if ((*A)->index >= 12)
		{
			push_b(A, B);
			if ((*B)->index > mean_left && stargets_in_B(*B, mean_left))
			{
				if ((*A)->index <= 11)
					rotate_both(A, B);
				else
					rotate_b(B);
			}
		}
		else
			rotate_a(A);
	}
}

int	only_three_to_eight(t_stack *A)
{
	A = top_stack(A);
	while (A)
	{
		if (A->index <= 2 || A->index >= 9)
			return (0);
		A = A->next;
	}
	return (1);
}

int	only_six_seven_eight(t_stack *A)
{
	A = top_stack(A);
	while (A)
	{
		if (A->index <= 5 || A->index >= 9)
			return (0);
		A = A->next;
	}
	return (1);
}

void    last_purge(t_stack **A, t_stack **B)
{
	*A = top_stack(*A);
	while (!only_three_to_eight(*A))
	{
		if ((*A)->index >= 3 && (*A)->index <= 8)
			rotate_a(A);
		else
			push_b(A, B);
	}
	while (!only_six_seven_eight(*A))
	{
		if ((*A)->index >= 6 && (*A)->index <= 8)
			rotate_a(A);
		else
			push_b(A, B);
	}
}

void	decrease_indexes(t_stack *A)
{
	A = top_stack(A);
	while (A)
	{
		A->index -= 6;
		A = A->next;
	}
}

void	increase_indexes(t_stack *A)
{
	A = top_stack(A);
	while (A)
	{
		A->index += 6;
		A = A->next;
	}
}

t_target	*best_target(t_stack *A, t_stack *B, int head, int tail)
{
	t_target *above_head;
	t_target *below_tail;
	int	shortest_to_ah;
	int	shortest_to_bt;

	above_head = new_target();
	below_tail = new_target();
	shortest_to_ah = 0;
	shortest_to_bt = 0;
	intel_target(head, above_head, A, B);
	intel_target(tail, below_tail, A, B);
	if (target_in_stack(above_head->index, A))
		shortest_to_ah = shortest_way_to_target(above_head->index, A);
	else
		shortest_to_ah = shortest_way_to_target(above_head->index, B);
	if (target_in_stack(below_tail->index, A))
		shortest_to_bt = shortest_way_to_target(below_tail->index, A);
	else
		shortest_to_bt = shortest_way_to_target(below_tail->index, B);
	if (abs_val(shortest_to_ah) <= abs_val(shortest_to_bt))
		return (above_head);
	return (below_tail);
}

void plug_nine_lucky(t_target *target, t_stack **A, t_stack **B, int *ht)
{
	if (target->stack == 'b')
	{
		if (target->destination == 'u')
		{
			extract_target_ontop(*ht, A);
			extract_target_ontop(target->index, B);
			push_a(A, B);
		}
		else if (target->destination == 'd')
		{
			extract_target_ontop(*ht, A);
			rotate_a(A);
			extract_target_ontop(target->index, B);
			push_a(A, B);
			rotate_a(A);
		}
	}
	else if (target->stack == 'a' && target->location == 'u')
	{

		extract_target_ontop(target->index, A);
		push_b(A, B);
		extract_target_ontop(*ht, A);
		push_a(A,B);
		if (target->destination == 'd')
			rotate_a(A);
	}
	if (target->index > *ht)
		(*ht)++;
	else
		(*ht)--;
}

/*

	//tant que A n est pas ordonnee de 0 a 11
		//determiner la cible la plus proche
		l'extraire
		les produits d'extraction :
			si la cible choisie est dans le haut de B
				si la cible choisie est a destination du top de A
					prise rendue accessible
					produits au bottom de A
				si la cible choisie est a destination du bottom de A
					prise rendue accessible
					produits au top de A

		//	si la cible choisie est dans le haut de A
				si la cible choisie est a destination du top de A
					produits au bottom de A
					la cible est push sur B durant le deblayage,
						puis repush sur A une fois celui-ci termine
				si la cible choisie est a destination du bottom de A
					prise rendue accessible
					produits au top de B
			
		//	si la cible choisie est dans le bas de A
				si la cible choisie est a destination du top de A
					prise rendue accessible
					produits au top de B
				si la cible choisie est a destination du bottom de A
					produits au top de A
					la cible est push sur B durant le deblayage,
						puis repush sur A une fois celui-ci termine
	
}
*/

void    nine_lucky(t_stack **A, t_stack **B, t_stack *S)
{
	t_target	*btarget;
	int	head;
	int	tail;

	(void)S; // penser a virer les S de toute la part 1
	btarget = NULL;
	head = 6;
	tail = 8;
	while (head || tail < 11) 
	// ainsi, best target n'est appelee que si head > 0 et tail < 11
	{
		btarget = best_target(*A, *B, head, tail);
		if (btarget->index < head)
		{
			plug_nine_lucky(btarget, A, B, &head);
		}
		else
		{
			plug_nine_lucky(btarget, A, B, &tail);
		}
	}
}


void    part_one(t_stack **A, t_stack **B, t_stack *S)
{
    purge_after_twelve(A, B);
	showABS(*A, *B, S, len_stack(S));
	last_purge(A, B);
    decrease_indexes(*A);
	algo_three(A);
    increase_indexes(*A);
    nine_lucky(A, B, S);
}

/*------------------------FONCTIONNEL---------------------------------*/

void	initialize_priority(int *priority, t_stack *A, t_stack *B)
{
	int bottom_a;

	if (len_stack(B) >= 2)
	{
		bottom_a = bottom_stack(A)->index;
		priority[0] = bottom_a + 1;
		priority[1] = priority[0] + 1;
	}
}

/*

int *initialize_secondary(int *secondary, t_stack *B)
{

}

void    lists_update_part_two(int *prio[], int *sec[], t_stack *A, t_stack *B)
{

}
*/

void    part_two(t_stack **A, t_stack **B)
{
    int priority[2];
    //int *secondary;
    //int best_choice;

    initialize_priority(priority, *A, *B);
	printf("part_two : priority[0] = %d ; priority[1] = %d\n", priority[0], priority[1]);
	/*
    initialize_secondary(secondary,*B);
    while (priority[0] != -1)
    {
        best_choice = best_priority_choice(priority, secondary, *A, *B);
        extract_priority_ontop(best_choice, secondary, A, B);
        send_and_plug_priority(best_choice, A, B);
        lists_update(priority, secondary, *B);
        (&priority, &secondary, *A, *B);
    }
	*/
}
/*
void    part_three(t_stack **A, t_stack **B)
{

}

void    part_four(t_stack **A, t_stack **B)
{

}

void    part_five(t_stack **A, t_stack **B)
{

}
*/
void    algo_beyond_seven(t_stack **A, t_stack **B, t_stack *S)
{
	part_one(A, B, S);
    part_two(A, B);
	/*
    while (!sorted_final_stack(*A))
    {
        part_three(A, B);
        part_four(A, B);
        part_five(A, B);
    }
	*/
}
