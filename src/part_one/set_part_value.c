/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_part_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:59:52 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 13:59:55 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_part_value(t_stack *a, int *part)
{
	if (a->index_max <= 100)
		*part = len_stack(a) / 7;
	else if (a->index_max <= 500)
		*part = len_stack(a) / 11;
}
