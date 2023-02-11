/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:59:31 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/11 23:59:31 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_stack_element(void)
{
    t_stack *element;

    element = malloc(sizeof(*element));
    if (!element)
        return (NULL);
    return (element);
}

void    initialize_stack_element(t_stack *element)
{
    element->index = -1;
    element->index_max = -1;
    element->initial_index_max = -1;
    element->nb = -1;
    element->next = NULL;
    element->precedent = NULL;
    element->spaces = -1;
	element->a_or_b = 'a';
    element->move = NULL;
}

t_stack *add_front(t_stack *stack, int nb)
{
    t_stack *element;

    element = new_stack_element();
    initialize_stack_element(element);
    element->nb = nb;
    element->next = stack;
    return (element);
}

void show_stack(t_stack *stack)
{
    printf("-------------------\n");
    while (stack)
    {
        printf("%d\n", stack->nb);
        stack = stack->next;
    }
    printf("-------------------\n");
}

t_stack *array_to_stack(int *array, int len)
{
    t_stack *element;

    len--;
    element = add_front(NULL, array[len]);
    element->spaces = 15 - len_int(element->index); //element->nb passe en element->index
    while (--len >= 0)
    {
        element = add_front(element, array[len]);
        element->spaces = 15 - len_int(element->index); //element->nb passe en element->index
    }
    return (element);
}

int len_stack(t_stack *stack)
{
    int len;

    len = 0;
	stack = top_stack(stack);
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    return (len);
}