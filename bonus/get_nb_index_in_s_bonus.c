/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_index_in_s_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:14:47 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:33 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
