/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_priority.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:03:49 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 15:04:05 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_priority(int *priority, t_stack *a, t_stack *b)
{
	int	bottom_a;

	if (len_stack(b) >= 2)
	{
		bottom_a = bottom_stack(a)->index;
		priority[0] = bottom_a + 1;
		priority[1] = priority[0] + 1;
	}
	else if (len_stack(b) == 1)
	{
		priority[0] = b->index;
		priority[1] = 0;
	}
}
