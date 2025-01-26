/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:06:02 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 15:06:03 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*which_stack(int target, t_stack *a, t_stack *b)
{
	if (target_in_stack(target, a))
		return (a);
	return (b);
}
