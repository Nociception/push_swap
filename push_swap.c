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

free les targets perdantes

stocker les les mouvements dans une liste chainee pour ensuite l'optimiser/ecremer
*/
int main(int ac, char *av[])
{
    int *array;
    int *sorted;
    int len;
    t_stack *a;
    t_stack *b;
    t_stack *s;

    len = ac - 1;
    a = NULL;
    b = NULL;
    s = NULL;
    if (ac > 1)
    {
        array = retrieve_data(len, av);
        sorted = sort_array(array, len);
        a = array_to_stack(array, len);
        s = array_to_stack(sorted, len);
        add_stack_backlinks(a);
        index_on_s(s, len);
        index_on_a(a, s);

        show_abs(a, b, s, len);

		algo_length(&a, &b, s, len);
        show_abs(a, b, s, len);
    }
    printf("MAIN : -----------------------------------\n");
    printf("MAIN : traitement termine\n");
	print_moves(a, b);
    if (sorted_final_stack_ontop(a))
            printf("MAIN : STACK SORTED !!!\n");
        else
            printf("MAIN : Stack not sorted :( :( :(\n");
    printf("MAIN : return (0) imminent ; AUCUN CRASH\n");
    return (0);
}