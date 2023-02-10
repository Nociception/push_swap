/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:46:55 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/10 21:19:58 by nstoutze         ###   ########.fr       */
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
            a->move = new_struct_move();
        a->index_max = s->index_max;
        a->initial_index_max = s->initial_index_max;
        a = a->next;
    }
}

t_stack *get_element_index_in_stack(t_stack *stack, int index)
{

	stack = top_stack(stack);
	while (stack)
	{
		if (stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);

}

t_stack	*index_stack(t_stack *a, t_stack *b, int index)
{
	if (a && target_in_stack(index, a))
		return (get_element_index_in_stack(a, index));
	if (b && target_in_stack(index, b))
		return (get_element_index_in_stack(b, index));
	return (NULL);
}