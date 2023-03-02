/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_beyond_seven.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:35:04 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/17 18:35:04 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_beyond_seven(t_stack **a, t_stack **b, t_stack *s)
{
	part_one(a, b);
	part_two(a, b, s);
}
