/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_on_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:07:36 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 19:30:07 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_on_s(t_stack *s, int len)
{
	int	index;

	index = 0;
	s = top_stack(s);
	while (s)
	{
		s->index = index;
		s->index_max = len - 1;
		index++;
		s = s->next;
	}
}
