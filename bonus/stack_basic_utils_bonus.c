/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:15:44 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:15:44 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*new_stack_element(void)
{
	t_stack	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->index = -1;
	element->index_max = -1;
	element->nb = -1;
	element->next = NULL;
	element->precedent = NULL;
	element->a_or_b = 'a';
	element->move = NULL;
	return (element);
}

t_stack	*add_front(t_stack *stack, int nb)
{
	t_stack	*element;

	element = new_stack_element();
	element->nb = nb;
	element->next = stack;
	return (element);
}

t_stack	*array_to_stack(int *array, int len)
{
	t_stack	*element;

	len--;
	if (are_numbers_unique(array, len))
	{
		element = add_front(NULL, array[len]);
		while (--len >= 0)
			element = add_front(element, array[len]);
		return (element);
	}
	else
		return (NULL);
}

int	len_stack(t_stack *stack)
{
	int	len;

	len = 0;
	stack = top_stack(stack);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	pos_index_in_stack(int index, t_stack *stack)
{
	int	position;

	position = 0;
	stack = top_stack(stack);
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (0);
}

/*
-----INUTILE POUR LE RENDU-----
void	show_stack(t_stack *stack)
{
	printf ("-------------------\n");
	while (stack)
	{
		printf("%d\n", stack->index);
		stack = stack->next;
	}
	printf ("-------------------\n");
}
*/