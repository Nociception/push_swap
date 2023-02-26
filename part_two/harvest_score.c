/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harvest_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:07:17 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 15:18:08 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	harvest_score_from_top(t_stack *stack, int target, int threshold)
{
	int	score ;

	score = 0;
	stack = top_stack(stack);
	while (stack && stack->index != target)
	{
		if (stack->index <= threshold)
			score++;
		else
			score += 2;
		stack = stack->next;
	}
	return (score);
}

static int	harvest_score_from_bottom(t_stack *stack, int target, int thr)
{
	int	score ;

	score = 0;
	stack = bottom_stack(stack);
	while (stack && stack->index != target)
	{
		if (stack->index <= thr)
			score++;
		else
			score += 2;
		stack = stack->precedent;
	}
	return (score);
}

int	harvest_score(t_stack *stack, int target, int threshold)
{
	int	middle;
	int	score;

	middle = len_stack(stack) / 2;
	if (pos_index_in_stack(target, stack) <= middle)
		score = harvest_score_from_top(stack, target, threshold);
	else
		score = harvest_score_from_bottom(stack, target, threshold);
	return (score);
}
