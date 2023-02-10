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

void    show_abs(t_stack *a, t_stack *b, t_stack *s, int len)
{
    int len_a;
    int len_b;

    len_a = len_stack(a);
    len_b = len_stack(b);
    printf("----------------------------------------------\n");
    while (s)
    {
        if (len_a == len)
        {
            printf("%d%s", a->index, spaces(a->spaces)); // remplace provisoirement par index
            len_a--;
            a = a->next;
        }
        else
            printf("               ");
        if (len_b == len)
        {
            printf("%d%s", b->index, spaces(b->spaces)); // remplace provisoirement par index
            len_b--;
            b = b->next;
        }
        else
            printf("               ");
        printf("%d\n", s->index); // remplace provisoirement par index
        len--;
        s = s->next;
    }
    printf("a              b              s\n");
    printf("----------------------------------------------\n");
}