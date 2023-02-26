/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_threshold.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:04:45 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 15:05:00 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	define_threshold(t_stack *b, int index_max)
{
	int	min;
	int	max;
	int	threshold;

	threshold = 1;
	if (len_stack(b) == 0)
		return (1);
	min = index_min_in_stack(b);
	max = index_max_in_stack(b);
	if (index_max <= 100)
		threshold = min + (max - min) / 7;
	else if (index_max <= 500)
		threshold = min + (max - min) / 14;
	return (threshold);
}
