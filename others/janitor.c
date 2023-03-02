/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   janitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:37:20 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 20:16:15 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	janitor(void *dust)
{
	if (dust)
	{
		free(dust);
		dust = NULL;
	}
}

void	stack_janitor(t_stack **a, t_stack **b, t_stack **s)
{
	t_stack	*next;

	next = NULL;
	*a = top_stack(*a);
	while (*a)
	{
		free(*a);
		next = (*a)->next;
		*a = next;
	}
	*b = top_stack(*b);
	while (*b)
	{
		free(*b);
		next = (*b)->next;
		*b = next;
	}
	*s = top_stack(*s);
	while (*s)
	{
		free(*s);
		next = (*s)->next;
		*s = next;
	}
}
