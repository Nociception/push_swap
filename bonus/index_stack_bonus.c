/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:15:07 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:42 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*index_stack(t_stack *a, t_stack *b, int index)
{
	if (a && target_in_stack(index, a))
		return (get_element_index_in_stack(a, index));
	if (b && target_in_stack(index, b))
		return (get_element_index_in_stack(b, index));
	return (NULL);
}
