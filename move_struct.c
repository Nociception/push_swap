#include "push_swap.h"

void	initialize_move(t_move *move)
{
	move->m1 = ' ';
	move->m2 = ' ';
	move->m3 = ' ';
	move->precedent = NULL;
	move->next = NULL;
}

t_move *new_struct_move(void)
{
	t_move *move;

    move = malloc(sizeof(*move));
    if (!move)
        return (NULL);
	initialize_move(move);
    return (move);
}

//add back, ou add front puis reverse a la fin du traitement