/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:46:55 by nstoutze          #+#    #+#             */
/*   Updated: 2023/01/28 20:47:28 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    index_on_S(t_stack *S, int len)
{
    int index;

    index = 0;
    S = top_stack(S);
    while (S)
    {
        S->index = index;
        S->index_max = len - 1;
        index++;
        S = S->next;
    }
}

int get_nb_index_in_S(int Anb, t_stack *S)
{
    S = top_stack(S);
    while (S)
    {
        if (S->nb == Anb)
            return (S->index);
        S = S->next;
    }
    return (-1);
}

void    index_on_A(t_stack *A, t_stack *S)
{
    A = top_stack(A);
    while (A)
    {
        A->index = get_nb_index_in_S(A->nb, S);
        A->index_max = S->index_max;
        A = A->next;
    }
}