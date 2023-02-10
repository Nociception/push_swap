#include "push_swap.h"

void    algo_length(t_stack **a, t_stack **b, t_stack *s, int len)
{
    int ssot;

	//printf("algo_length : Entree\n");
    ssot = sorted_final_stack_ontop(*a);
    if (len == 2 && (*a)->index)
        swap_a(a, *b);
    else if (len == 3 && !ssot)
        algo_three(a, *b);
    else if (len == 4 && !ssot)
    	algo_four(a, *b);
	else if (len == 5 && !ssot)
		algo_five(a, b);
	else if (len == 6 && !ssot)
		algo_six(a, b);
	else if (len > 6 && !ssot)
		algo_beyond_seven(a, b, s);
}
