/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_in_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:38:50 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 20:16:25 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	range_in_stack(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (min + i <= max)
	{
		if (target_in_stack(min + i, stack))
			return (1);
		i++;
	}
	return (0);
}
