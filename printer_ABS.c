#include "push_swap.h"
int u = 1;

char *spaces(int nb)
{
    char *blanks;
    int i;

    i = -1;
    blanks = malloc(sizeof(char) * (nb + 1));
    if (!blanks)
        return (NULL);
    while (++i < nb)
        blanks[i] = ' ';
    blanks[nb] = '\0';
    return (blanks);
}

void    showABS(t_stack *A, t_stack *B, t_stack *S, int len)
{
    int lenA;
    int lenB;

    lenA = len_stack(A);
    lenB = len_stack(B);
    printf("----------------------------------------------\n");
    while (S)
    {
        if (lenA == len)
        {
            printf("%d%s", A->index, spaces(A->spaces)); // remplace provisoirement par index
            lenA--;
            A = A->next;
        }
        else
            printf("               ");
        if (lenB == len)
        {
            printf("%d%s", B->index, spaces(B->spaces)); // remplace provisoirement par index
            lenB--;
            B = B->next;
        }
        else
            printf("               ");
        printf("%d\n", S->index); // remplace provisoirement par index
        len--;
        S = S->next;
    }
    printf("A              B              S\n");
    printf("----------------------------------------------\n");
}