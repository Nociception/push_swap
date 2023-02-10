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

void    index_on_s(t_stack *s, int len)
{
    int index;

    index = 0;
    s = top_stack(s);
    while (s)
    {
        s->index = index;
        s->index_max = len - 1;
        s->initial_index_max = len - 1;
        index++;
        s = s->next;
    }
}

int get_nb_index_in_s(int a_nb, t_stack *s)
{
    s = top_stack(s);
    while (s)
    {
        if (s->nb == a_nb)
            return (s->index);
        s = s->next;
    }
    return (-1);
}

void    index_on_a(t_stack *a, t_stack *s)
{
    a = top_stack(a);
    while (a)
    {
        a->index = get_nb_index_in_s(a->nb, s);
        if (a->index == 0)
            a->move = new_move();
        a->index_max = s->index_max;
        a->initial_index_max = s->initial_index_max;
        a = a->next;
    }
}