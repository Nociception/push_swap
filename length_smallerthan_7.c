#include "push_swap.h"

int are_directneighbors(int x, int y, int len)
{
    printf("aredirect : Entree\n");
    printf("are : x = %d ; y = %d ; len = %d\n", x, y, len);
    if ((x + 1)%len == y || (x - 1)%len == y)
        return (1);
    return (0);
}

char peer_to_order(t_stack *A, t_stack *B, int len)
{
    printf("peer : Entree\n");
    A = top_stack(A);
    printf("peer : A->nb = %d ; A->index = %d\n", A->nb, A->index);
    if (B)
    {
        printf("peer : entree dans le premier if \n");
        B = top_stack(B);
        printf("peer : B->nb = %d ; B->index = %d\n", B->nb, B->index);
        if (are_directneighbors(A->index, B->index, len))
            return ('B');
    }
    if (are_directneighbors(A->index, A->next->index, len))
    {
        printf("peer : entree dans le deuxieme if \n");
        return ('s');
    }
    if (are_directneighbors(A->index, bottom_stack(A)->index, len))
    {
        printf("peer : entree dans le troisieme if \n");
        return ('b');
    }
    return ('n');
}