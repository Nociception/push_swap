#include "push_swap.h"

void	ra_twice_if_necessary(t_stack **a)
{
	if (*a && (*a)->next)
	{
		rotate_a(a);
		if (!sorted_final_stack(*a))
			rotate_a(a);
	}
}

static void	moves_tt_dneighbors(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		push_a(a, b);
		if (!top_second_in_order(*a))
			swap_a(a);
		ra_twice_if_necessary(a);
	}
}

static void	moves_ts_direct_neighbors(t_stack **a, t_stack *b)
{
	if (*a && (*a)->next)
	{
		if (!top_second_in_order(*a))
		{
			swap_a(a);
			if (both_tops_dneighbors(*a, b))
				return ;
		}
		ra_twice_if_necessary(a);
	}
}

static void	moves_tb_direct_neighbors(t_stack **a)
{
	if (*a)
	{
		if (!top_bottom_in_order(*a))
		{
			reverserotate_a(a);
			swap_a(a);
			ra_twice_if_necessary(a);
		}
		rotate_a(a);
	}
	
}

void	algo_five(t_stack **a, t_stack **b)
{
	while (!sorted_final_stack(*a))
	{
		if (both_tops_dneighbors(*a, *b))
			moves_tt_dneighbors(a, b);
		else if (top_second_dneighbors(*a))
			moves_ts_direct_neighbors(a, *b);
		else if (top_bottom_dneighbors(*a))
			moves_tb_direct_neighbors(a);
		else
			push_b(a, b);
	}
	set_sorted_final_stack_ontop(a);
}

/*
Tant que la pile n'est pas triée
	si le top et le top de B sont voisins
		si le top et le top de B sont ordonnés
			pa
		sinon
			pa
			sa
		ra_twice_if_necessary
	si le top et le second sont voisins
		si le top et le second ne sont pas ordonnés
			sa
		ra_twice_if_necessary
	si le top et le bottom sont voisins
		si le top et le bottom ne pas sont ordonnés
			rra
			sa
		ra_twice_if_necessary
	sinon
		pb
placement de la pile triee


*/