/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_on_a_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:14:53 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:37 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
