/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:14:29 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:25 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sorted_final_stack(t_stack *a)
{
	int	i;
	int	mod;

	a = top_stack(a);
	if (a)
	{
		i = 0;
		mod = a->index_max + 1;
		while (++i <= mod && a->next && (a->index + 1) % mod == a->next->index)
			a = a->next;
		if (i == mod && !(a->next))
			return (1);
	}
	return (0);
}

void	set_sorted_final_stack_ontop(t_stack **a, t_stack *b)
{
	if (*a && sorted_final_stack(*a))
		extract_target_ontop(0, a, &b);
}

int	sorted_final_stack_ontop(t_stack *a)
{
	return (a && sorted_final_stack(a) && !(top_stack(a)->index));
}

int	is_equal_to_s(t_stack *a, t_stack *s)
{
	while (s && a && s->index == a->index)
	{
		a = a->next;
		s = s->next;
	}
	if (s || a)
		return (0);
	return (1);
}
