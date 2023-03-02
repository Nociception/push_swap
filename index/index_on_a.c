/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_on_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:33:53 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/28 22:35:47 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_on_a(t_stack *a, t_stack *s)
{
	a = top_stack(a);
	while (a)
	{
		a->index = get_nb_index_in_s(a->nb, s);
		a->index_max = s->index_max;
		a = a->next;
	}
}
