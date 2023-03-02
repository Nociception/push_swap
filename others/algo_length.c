/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:56:44 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 20:15:58 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_length(t_stack **a, t_stack **b, t_stack *s, int len)
{
	int	sfsot;

	sfsot = sorted_final_stack_ontop(*a);
	if (sorted_final_stack(*a))
	{
		if (!sfsot)
			extract_target_ontop(0, a, b);
	}
	else if (len == 2 && (*a)->index)
		swap_a(a);
	else if (len == 3 && !sfsot)
		algo_three(a);
	else if (len == 4 && !sfsot)
		algo_four(a, *b);
	else if (len == 5 && !sfsot)
		algo_five(a, b);
	else if (len == 6 && !sfsot)
		algo_six(a, b);
	else if (len >= 7 && !sfsot)
		algo_beyond_seven(a, b, s);
}
