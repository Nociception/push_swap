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

void    algo_three(t_stack **a)
{
    int first;
    int second;
    int third;

    first = (*a)->index;
    second = (*a)->next->index;
    third = (*a)->next->next->index;
    if (first == 1 && second == 0 && third == 2)
        swap_a(a);
    else if (first == 1 && second == 2 && third == 0)
        reverserotate_a(a);
    else if (first == 2 && second == 0 && third == 1)
        rotate_a(a);
    else if (first == 0 && second == 2 && third == 1)
    {
        swap_a(a);
        rotate_a(a);
    }
    else if (first == 2 && second == 1 && third == 0)
    {
        swap_a(a);
        reverserotate_a(a);
    }
}