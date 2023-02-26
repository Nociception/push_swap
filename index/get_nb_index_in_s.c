/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_index_in_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:31:27 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 19:26:22 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_nb_index_in_s(int a_nb, t_stack *s)
{
	s = top_stack(s);
	while (s)
	{
		if (s->nb == a_nb)
			return (s->index);
		s = s->next;
	}
	return (-1);
}
