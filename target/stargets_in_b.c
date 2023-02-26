/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stargets_in_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:42:57 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 19:27:35 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stargets_in_b(t_stack *b, int mean_left)
{
	while (b)
	{
		if (b->index <= mean_left)
			return (1);
		b = b->next;
	}
	return (0);
}
