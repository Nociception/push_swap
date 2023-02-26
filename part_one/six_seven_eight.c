/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_seven_eight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:06:19 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 14:53:33 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	six_seven_eight(t_stack **a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first == 7 && second == 6 && third == 8)
		swap_a(a, b);
	else if (first == 7 && second == 8 && third == 6)
		reverserotate_a(a, b);
	else if (first == 8 && second == 6 && third == 7)
		rotate_a(a, b);
	else if (first == 6 && second == 8 && third == 7)
	{
		swap_a(a, b);
		rotate_a(a, b);
	}
	else if (first == 8 && second == 7 && third == 6)
	{
		swap_a(a, b);
		reverserotate_a(a, b);
	}
}
