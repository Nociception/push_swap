/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_twelve_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:58:46 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 13:59:08 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	only_twelve_first(t_stack *a)
{
	a = top_stack(a);
	while (a)
	{
		if (a->index >= 12)
			return (0);
		a = a->next;
	}
	return (1);
}
