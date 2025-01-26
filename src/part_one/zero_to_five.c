/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_to_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:07:00 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 14:54:30 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	zero_to_five(t_stack **a, t_stack **b)
{
	int	target;

	while (top_stack(*a)->index)
	{
		target = top_stack(*a)->index - 1;
		extract_target_ontop(target, a, b);
		push_a(a, b);
	}
}
