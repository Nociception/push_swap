/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_three_to_eight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:04:45 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 14:04:58 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	only_three_to_eight(t_stack *a)
{
	a = top_stack(a);
	while (a)
	{
		if (a->index <= 2 || a->index >= 9)
			return (0);
		a = a->next;
	}
	return (1);
}
