/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:07:18 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 15:59:22 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part_one(t_stack **a, t_stack **b)
{
	purge_after_twelve(a, b);
	last_purge(a, b);
	if (len_stack(*a) >= 3)
		six_seven_eight(a);
	else if (len_stack(*a) == 2 && (*a)->index > (*a)->next->index)
		swap_a(a);
	zero_to_five(a, b);
}
