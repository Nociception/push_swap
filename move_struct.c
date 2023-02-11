/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:58:27 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/11 23:58:27 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_move(t_move *move)
{
	move->first = ' ';
	move->second = ' ';
	move->third = ' ';
	move->precedent = NULL;
	move->next = NULL;
}

t_move	*new_struct_move(void)
{
	t_move	*move;

	move = malloc(sizeof(*move));
	if (!move)
		return (NULL);
	initialize_move(move);
	return (move);
}

t_move	*moves_chain_tail(t_move *move)
{
	while (move->next)
		move = move->next;
	return (move);
}

t_move	*add_back_move(t_move *move, char first, char second, char third)
{
	t_move	*new_move;

	new_move = new_struct_move();
	initialize_move(new_move);
	new_move->first = first;
	new_move->second = second;
	new_move->third = third;
	new_move->next = move;
	move = moves_chain_tail(move);
	move->next = new_move;
	new_move->precedent = move;
	new_move->next = NULL;
	return (move);
}

void	print_moves(t_stack *a, t_stack *b)
{
	t_stack	*index_zero;
	t_move	*moves;

	index_zero = index_stack(a, b, 0);
	moves = index_zero->move;
	printf("Here are the raw moves :\n");
	while (moves)
	{
		printf("%c", moves->first);
		printf("%c", moves->second);
		if (moves->third != ' ')
			printf("%c", moves->third);
		printf("\n");
		moves = moves->next;
	}
	printf("print_moves DONE\n");
}
