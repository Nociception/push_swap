#include "push_swap.h"
/*
retravailler l'algo 6 avant d'entamer l'algo principal

Norme (variable lettre majuscule)
headers
Bonus : checker
include printf
parsing (nb uniques notamment)
structure englobante (notamment pour compter le nombre de moves)

ajouter une data a la structure t_stack pour generer un indice de circonstance
OU
jouer sur l'indice max
*/
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

        algo_length(&A, &B, len);

        showABS(A, B, S, len);
    }
    printf("MAIN : -----------------------------------\n");
    printf("MAIN : traitement termine\n");
    if (sorted_final_stack_ontop(A))
            printf("MAIN : STACK SORTED !!!\n");
        else
            printf("MAIN : Stack not sorted :( :( :(\n");
    printf("MAIN : return (0) imminent ; AUCUN CRASH\n");
    return (0);
}