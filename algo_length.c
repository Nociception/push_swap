#include "push_swap.h"

void    algo_length(t_stack **A, t_stack **B, int len)
{
    int ssot;

    ssot = sorted_final_stack_ontop(*A);
    if (len == 2 && (*A)->index)
        swap_a(A);
    else if (len == 3 && !ssot)
        algo_three(A);
    else if (len == 4 && !ssot)
    	algo_four(A);
	else if (len == 5 && !ssot)
		algo_five(A, B);
	else if (len == 6 && !ssot)
		algo_six(A, B);
}
