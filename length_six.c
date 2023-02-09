#include "push_swap.h"

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

int	peer_in_order(t_stack *A, int x, int y)
{
	int	index_max;
	int range;

	if (A)
	{
		index_max = A->index_max;
		if ((x == 0 && y == index_max) || (x == index_max && y == 0))
			return (1);
		range = abs_val(x - y);
		if (range == 1)
			return (1);
	}
	return (0);
}

static int	peer_peer_peer(t_stack *A)
{
	int first_peer;
	int second_peer;
	int third_peer;
	int second_third;
	int fourth_fifth;

	if (len_stack(A) == 6)
	{
		A = top_stack(A);
		first_peer = peer_in_order(A, A->index, A->next->index);
		A = A->next->next;
		second_third = peer_in_order(A, A->precedent->index, A->index);
		second_peer = peer_in_order(A, A->index, A->next->index);
		A = A->next->next;
		fourth_fifth = peer_in_order(A, A->precedent->index, A->index);
		third_peer = peer_in_order(A, A->index, A->next->index);
		return (first_peer && second_peer && third_peer && !second_third && !fourth_fifth);
	}
	return (0);
}

static void	moves_ppp(t_stack **A, t_stack **B)
{
	if (*A && (*A)->next)
	{
		push_b(A,B);
		push_b(A,B);
		rotate_a(A);
		rotate_a(A);
		push_a(A,B);
		push_a(A,B);
	}
}

int	top_second_ms_dneighbors(t_stack *A, t_stack *B)
{
	if (A && B && B->next)
	{
		A = top_stack(A);
		B = (top_stack(B))->next;
		return (direct_neighbors(A->index, B->index, A->index_max));
	}
	return (0);
}

void	moves_ts_ms_dneighbors(t_stack **B)
{
	if (*B && (*B)->next)
	{
		*B = top_stack(*B);
		swap_b(B);
	}
}

int	second_second_ms_dneighbors(t_stack *A, t_stack *B)
{
	if (A && A->next && B && B->next)
	{
		A = (top_stack(A))->next;
		B = (top_stack(B))->next;
		return (direct_neighbors(A->index, B->index, A->index_max));
	}
	return (0);
}

void	moves_ss_ms_dneighbors(t_stack **A, t_stack **B)
{
	if (*A && (*A)->next && *B && (*B)->next)
	{
		*A = top_stack(*A);
		*B = top_stack(*B);
		swap_both(A, B);
	}
}

/*
tant que (pile non triee)
{
	si linked_unsorted_stack (composee donc de sequence ordonnees)
		reperer la sequence la plus courte
		la push vers B
		reperer la tete de la sequence sur laquelle push le top de B
		extraire cette tete au top de A
		push la sequence de B sur A
	si bottomA ordonne avec topB
		pa
	si top ordonne avec top B
		pa
	si top voisin de secondB
		sb
	si top ordonne avec second
		ra
	si top voisin de second
		sa
	si top ordonne avec bottom
		ra
	si top voisin de bottom
		rra
	sinon
		pb
}
placer la pile triee
*/


void algo_six(t_stack **A, t_stack **B)
{
	if (*A)
	{
		while (!sorted_final_stack(*A))
		{
			if (peer_peer_peer(*A))
				moves_ppp(A, B);
			else if (both_tops_dneighbors(*A, *B))
				moves_tt_dneighbors(A, B);
			else if (top_second_dneighbors(*A))
				moves_ts_direct_neighbors(A, *B);
			else if (top_bottom_dneighbors(*A))
				moves_tb_direct_neighbors(A);
			else if (top_second_ms_dneighbors(*A, *B))
				moves_ts_ms_dneighbors(B);
			else if (second_second_ms_dneighbors(*A, *B))
				moves_ss_ms_dneighbors(A, B);
			else
				push_b(A, B);
		}
	set_sorted_final_stack_ontop(A);
	}
}


/*

peerpeerpeer :


5 3 2 6 1 4 provoque des mouvements a la con
2 3 1 6 4 5 provoque une boucle infinie (pattern des mouvements peerpeerpeer detecte)
1     4     6     2     5     3   pose un probleme (resolu avec la recherche chez le second de B)
2 6 1 3 5 4

Tant que la pile n'est pas triée
  si peerpeerpeer
    pb
    pb
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
      ra
		ra
  si le top et le second de B sont voisins
    sb
    pa
	sinon
		pb
placement de la pile triee

*/
