/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_priority_choice.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:08:12 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 15:08:13 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	best_priority_choice(t_stack *a, t_stack *b, int *priority, int threshold)
{
	int	score_first;
	int	score_second;

	if (priority[1] < 0)
		return (priority[0]);
	if (target_in_stack(priority[0], a))
		score_first = harvest_score(a, priority[0], threshold);
	else
		score_first = harvest_score(b, priority[0], threshold);
	if (target_in_stack(priority[1], a))
		score_second = harvest_score(a, priority[1], threshold);
	else
		score_second = harvest_score(b, priority[1], threshold);
	if (score_first <= score_second)
		return (priority[0]);
	return (priority[1]);
}
