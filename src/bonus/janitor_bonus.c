/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   janitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:15:14 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:46 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
