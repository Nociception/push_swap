/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:23:57 by nstoutze          #+#    #+#             */
/*   Updated: 2023/01/29 21:11:16 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algo_three(t_stack **A)
{
    int first;
    int second;
    int third;

    first = (*A)->index;
    second = (*A)->next->index;
    third = (*A)->next->next->index;
    if (first == 1 && second == 0 && third == 2)
        swap_a(A);
    else if (first == 1 && second == 2 && third == 0)
        reverserotate_a(A);
    else if (first == 2 && second == 0 && third == 1)
        rotate_a(A);
    else if (first == 0 && second == 2 && third == 1)
    {
        swap_a(A);
        rotate_a(A);
    }
    else if (first == 2 && second == 1 && third == 0)
    {
        swap_a(A);
        reverserotate_a(A);
    }
}