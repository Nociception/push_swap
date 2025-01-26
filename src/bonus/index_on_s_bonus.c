/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_on_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:15:01 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:40 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
