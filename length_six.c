#include "push_swap.h"

static void	moves_tt_dneighbors(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		push_a(a, b);
		if (!top_second_in_order(*a))
			swap_a(a, *b);
		ra_twice_if_necessary(a, *b);
	}
}

static void	moves_ts_direct_neighbors(t_stack **a, t_stack *b)
{
	if (*a && (*a)->next)
	{
		if (!top_second_in_order(*a))
		{
			swap_a(a, b);
			if (both_tops_dneighbors(*a, b))
				return ;
		}
		ra_twice_if_necessary(a, b);
	}
}

static void	moves_tb_direct_neighbors(t_stack **a, t_stack *b)
{
	if (*a)
	{
		if (!top_bottom_in_order(*a))
		{
			reverserotate_a(a, b);
			swap_a(a, b);
			ra_twice_if_necessary(a, b);
		}
		rotate_a(a, b);
	}
	
}

int	peer_in_order(t_stack *a, int x, int y)
{
	int	index_max;
	int range;

	if (a)
	{
		index_max = a->index_max;
		if ((x == 0 && y == index_max) || (x == index_max && y == 0))
			return (1);
		range = abs_val(x - y);
		if (range == 1)
			return (1);
	}
	return (0);
}

static int	peer_peer_peer(t_stack *a)
{
	int first_peer;
	int second_peer;
	int third_peer;
	int second_third;
	int fourth_fifth;

	if (len_stack(a) == 6)
	{
		a = top_stack(a);
		first_peer = peer_in_order(a, a->index, a->next->index);
		a = a->next->next;
		second_third = peer_in_order(a, a->precedent->index, a->index);
		second_peer = peer_in_order(a, a->index, a->next->index);
		a = a->next->next;
		fourth_fifth = peer_in_order(a, a->precedent->index, a->index);
		third_peer = peer_in_order(a, a->index, a->next->index);
		return (first_peer && second_peer && third_peer && !second_third && !fourth_fifth);
	}
	return (0);
}

static void	moves_ppp(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next)
	{
		push_b(a,b);
		push_b(a,b);
		rotate_a(a, *b);
		rotate_a(a, *b);
		push_a(a,b);
		push_a(a,b);
	}
}

int	top_second_ms_dneighbors(t_stack *a, t_stack *b)
{
	if (a && b && b->next)
	{
		a = top_stack(a);
		b = (top_stack(b))->next;
		return (direct_neighbors(a->index, b->index, a->index_max));
	}
	return (0);
}

void	moves_ts_ms_dneighbors(t_stack *a, t_stack **b)
{
	if (*b && (*b)->next)
	{
		*b = top_stack(*b);
		swap_b(a, b);
	}
}

int	second_second_ms_dneighbors(t_stack *a, t_stack *b)
{
	if (a && a->next && b && b->next)
	{
		a = (top_stack(a))->next;
		b = (top_stack(b))->next;
		return (direct_neighbors(a->index, b->index, a->index_max));
	}
	return (0);
}

void	moves_ss_ms_dneighbors(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		*a = top_stack(*a);
		*b = top_stack(*b);
		swap_both(a, b);
	}
}

/*
tant que (pile non triee)
{
	si linked_unsorted_stack (composee donc de sequence ordonnees)
		reperer la sequence la plus courte
		la push vers b
		reperer la tete de la sequence sur laquelle push le top de b
		extraire cette tete au top de a
		push la sequence de b sur a
	si bottomA ordonne avec topB
		pa
	si top ordonne avec top b
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


void algo_six(t_stack **a, t_stack **b)
{
	if (*a)
	{
		while (!sorted_final_stack(*a))
		{
			if (peer_peer_peer(*a))
				moves_ppp(a, b);
			else if (both_tops_dneighbors(*a, *b))
				moves_tt_dneighbors(a, b);
			else if (top_second_dneighbors(*a))
				moves_ts_direct_neighbors(a, *b);
			else if (top_bottom_dneighbors(*a))
				moves_tb_direct_neighbors(a, *b);
			else if (top_second_ms_dneighbors(*a, *b))
				moves_ts_ms_dneighbors(*a, b);
			else if (second_second_ms_dneighbors(*a, *b))
				moves_ss_ms_dneighbors(a, b);
			else
				push_b(a, b);
		}
	set_sorted_final_stack_ontop(a, *b);
	}
}


/*

peerpeerpeer :


5 3 2 6 1 4 provoque des mouvements a la con
2 3 1 6 4 5 provoque une boucle infinie (pattern des mouvements peerpeerpeer detecte)
1     4     6     2     5     3   pose un probleme (resolu avec la recherche chez le second de b)
2 6 1 3 5 4

Tant que la pile n'est pas triée
  si peerpeerpeer
    pb
    pb
	si le top et le top de b sont voisins
		si le top et le top de b sont ordonnés
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
  si le top et le second de b sont voisins
    sb
    pa
	sinon
		pb
placement de la pile triee

*/
