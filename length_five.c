#include "push_swap.h"

void	ra_twice_if_necessary(t_stack **A)
{
	if (*A && (*A)->next)
	{
		rotate_a(A);
		if (!sorted_final_stack(*A))
			rotate_a(A);
	}
}

static void	moves_tt_dneighbors(t_stack **A, t_stack **B)
{
	if (*A && *B)
	{
		push_a(A, B);
		if (!top_second_in_order(*A))
			swap_a(A);
		ra_twice_if_necessary(A);
	}
}

static void	moves_ts_direct_neighbors(t_stack **A, t_stack *B)
{
	if (*A && (*A)->next)
	{
		if (!top_second_in_order(*A))
		{
			swap_a(A);
			if (both_tops_dneighbors(*A, B))
				return ;
		}
		ra_twice_if_necessary(A);
	}
}

static void	moves_tb_direct_neighbors(t_stack **A)
{
	if (*A)
	{
		if (!top_bottom_in_order(*A))
		{
			reverserotate_a(A);
			swap_a(A);
			ra_twice_if_necessary(A);
		}
		rotate_a(A);
	}
	
}

void	algo_five(t_stack **A, t_stack **B)
{
	while (!sorted_final_stack(*A))
	{
		if (both_tops_dneighbors(*A, *B))
			moves_tt_dneighbors(A, B);
		else if (top_second_dneighbors(*A))
			moves_ts_direct_neighbors(A, *B);
		else if (top_bottom_dneighbors(*A))
			moves_tb_direct_neighbors(A);
		else
			push_b(A, B);
	}
	set_sorted_final_stack_ontop(A);
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