/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:57:53 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 20:10:24 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_and_backlinks(t_stack *a, t_stack *s, int len)
{
	add_stack_backlinks(a);
	index_on_s(s, len);
	index_on_a(a, s);
}

void	feed_stacks(int len, char *av[], t_stack **a, t_stack **s)
{
	int	*array;
	int	*sorted;

	array = fill_array_with_valid_data(len, av);
	if (len < 0)
		len = -len;
	sorted = NULL;
	if (array)
	{
		if (are_numbers_unique(array, len))
		{
			sorted = sort_array(array, len);
			*a = array_to_stack(array, len);
			*s = array_to_stack(sorted, len);
			index_and_backlinks(*a, *s, len);
		}
		else
		{
			janitor(array);
			ft_error("Error\n");
		}
	}
	janitor(array);
	janitor(sorted);
}
