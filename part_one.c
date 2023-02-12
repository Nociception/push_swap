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

void purge_after_twelve(t_stack **a, t_stack **b)
{
	//printf("purge_after_twelve : Entree\n");
	//le segfault est a trouver ici
	int	mean_left;

	mean_left = mean_two_positive_numbers(12, (*a)->initial_index_max);
	*a = top_stack(*a);
	*b = top_stack(*b);
	//printf("pat : boucle imminente\n");
	while (!only_twelve_first(*a))
	{
		if ((*a)->index >= 12)
		{
			//printf("pat(boucle) : entree dans le if\n");
			push_b(a, b);
			//printf("pat (boucle ; if) ; push_b passe\n");
			
			//printf("pat(boucle ; if) : (*b)->index = %d\n", (*b)->index);
			//printf("pat(boucle ; if) : mean_left = %d\n", mean_left);
			//printf("pat(boucle ; if) : stargets_in_b(*b, mean_left) = %d\n", stargets_in_b(*b, mean_left));
			
			if (*b && (*b)->index > mean_left && stargets_in_b(*b, mean_left))
			{
				//printf("pat (boucle ; if) : entree dans le if\n");
				if ((*a)->index <= 11)
				{
					//printf("pat(while ; if ; if) : entree dans le if\n");
					rotate_both(a, b);
				}
				else
				{
					//printf("pat(while ; if ; if) : entree dans le else\n");
					rotate_b(*a, b);
				}
			}
		}
		else
		{
			//printf("pat(boucle) : entree dans le else\n");
			rotate_a(a, *b);
		}
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
	//printf("last_purge : Entree\n");
	*a = top_stack(*a);
	//printf("last_purge : premiere boucle imminente\n");
	while (!only_three_to_eight(*a))
	{
		//printf("last_purge(premiere boucle) : debut iteration\n");
		if ((*a)->index >= 3 && (*a)->index <= 8)
			rotate_a(a, *b);
		else
			push_b(a, b);
	}
	while (!only_six_seven_eight(*a))
	{
		//printf("last_purge(deuxieme boucle) : debut iteration\n");
		if ((*a)->index >= 6 && (*a)->index <= 8)
			rotate_a(a, *b);
		else
			push_b(a, b);
	}
	//printf("last_purge : Fin\n");
}

void plug_nine_lucky(t_target *target, t_stack **a, t_stack **b, int *ht)
{
	//printf("plug_nine_lucky : Entree\n");
	//show_target_details(target);
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

void    nine_lucky(t_stack **a, t_stack **b, t_stack *s)
{
	//printf("nine_lucky : Entree\n");
	t_target	*btarget;
	int	head;
	int	tail;

	(void)s; // penser a virer les s de toute la part 1
	btarget = NULL;
	head = 6;
	tail = 8;
	while (head && tail < 12)
	// ainsi, best target n'est appelee que si head > 0 et tail < 11
	{
		//printf("nine_lucky (boucle) : Debut iteration\n");
		//printf("nice_lucky (boucle) : head = %d ; tail = %d\n", head, tail);
		btarget = best_target(*a, *b, head, tail);
		if (btarget->index < head)
		{
			//printf("part_one (boucle) : entree dans le if\n");
			plug_nine_lucky(btarget, a, b, &head);
		}
		else
		{
			//printf("part_one (boucle) : entree dans le else\n");
			plug_nine_lucky(btarget, a, b, &tail);
		}
		//printf("nine_lucky (boucle) : fin iteration\n");
		//printf("nice_lucky(boucle) : head = %d ; tail = %d\n", head, tail);
	}
	//printf("nine_lucky : Fin\n");
}

void    algo_six_seven_eight(t_stack **a, t_stack *b)
{
	//printf("algo_six_seven_eight : Entree\n");
	//print_moves(*a, b);
    int first;
    int second;
    int third;

    first = (*a)->index;
    second = (*a)->next->index;
    third = (*a)->next->next->index;
	//printf("algo_three : structure conditionnelle imminente\n");
    if (first == 7 && second == 6 && third == 8)
        swap_a(a, b);
    else if (first == 7 && second == 8 && third == 6)
        reverserotate_a(a, b);
    else if (first == 8 && second == 6 && third == 7)
        rotate_a(a, b);
    else if (first == 6 && second == 8 && third == 7)
    {
        swap_a(a, b);
        rotate_a(a, b);
    }
    else if (first == 8 && second == 7 && third == 6)
    {
        swap_a(a, b);
        reverserotate_a(a, b);
    }
}

void	lost_eleven(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		if (bottom_stack(*b)->index == 11)
			reverserotate_b(*a, b);
		if (top_stack(*b)->index == 11)
			push_a(a, b);
		if (top_stack(*a)->index == 11)
			rotate_a(a, *b);
	}
}

void    part_one(t_stack **a, t_stack **b, t_stack *s)
{
	s = top_stack(s);
	//printf("part_one : Entree\n");
    purge_after_twelve(a, b);
	//printf("part_one : purge_after_twelve passe\n");
	//print_moves(*a, *b);
	last_purge(a, b);
	//printf("part_one : last_purge passe\n");
	//print_moves(*a, *b);
	//printf("part_one : algo_six_seven_eight imminent\n");
	algo_six_seven_eight(a, *b);
	//printf("part_one : algo_six_seven_eight passe\n");
    nine_lucky(a, b, s);
	lost_eleven(a, b);
}