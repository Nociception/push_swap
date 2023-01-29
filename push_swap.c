#include "push_swap.h"
//Norme, headers, checker, include printf

int main(int ac, char *av[])
{
    int *array;
    int *sorted;
    int len;
    t_stack *A;
    t_stack *B;
    t_stack *S;

    len = ac - 1;
    A = NULL;
    B = NULL;
    S = NULL;
    if (ac > 1)
    {
        array = retrieve_data(len, av);
        sorted = sort_array(array, len);
        A = array_to_stack(array, len);
        S = array_to_stack(sorted, len);
        add_stack_backlinks(A);
        index_on_S(S, len);
        index_on_A(A, S);

        showABS(A, B, S, len);

        //algo_length(&A, &B, len);
		// retour sur length_four
		if (target_in_stack(0,A))
		{
			printf("MAIN : shortest_way_to_target(0, A) = %d\n", shortest_way_to_target(0, A));
			extract_target_ontop(0,&A);
		}
		else
			printf("MAIN : la cible n'est pas dans A\n");

        showABS(A, B, S, len);
    }
    printf("MAIN : -----------------------------------\n");
    printf("MAIN : return (0) imminent ; AUCUN CRASH\n");
    return (0);
}