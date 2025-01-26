/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:37:59 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 19:26:46 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*index_stack(t_stack *a, t_stack *b, int index)
{
	if (a && target_in_stack(index, a))
		return (get_element_index_in_stack(a, index));
	if (b && target_in_stack(index, b))
		return (get_element_index_in_stack(b, index));
	return (NULL);
}
