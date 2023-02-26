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

t_move	*new_struct_move(void)
{
	t_move	*move;

	move = malloc(sizeof(*move));
	if (!move)
		return (NULL);
	move->first = ' ';
	move->second = ' ';
	move->third = ' ';
	move->precedent = NULL;
	move->next = NULL;
	return (move);
}

t_move	*bottom_move(t_move *move)
{
	while (move->next)
		move = move->next;
	return (move);
}

t_move	*top_move(t_move *move)
{
	while (move)
		move = move->precedent;
	return (move);
}

t_move	*add_back_move(t_move *move, char first, char second, char third)
{
	t_move	*new_move;

	new_move = new_struct_move();
	new_move->first = first;
	new_move->second = second;
	new_move->third = third;
	new_move->next = move;
	move = bottom_move(move);
	move->next = new_move;
	new_move->precedent = move;
	new_move->next = NULL;
	return (move);
}
/*
void	print_moves(t_stack *a, t_stack *b)
{
	t_stack	*index_zero;
	t_move	*moves;
	int		n;

	printf("print_moves : Entree\n");
	index_zero = index_stack(a, b, 0);
	moves = index_zero->move;
	//printf("Here are the raw moves :\n");
	n = 0;
	while (moves)
	{
		//printf("print_moves(boucle) : debut iteration\n");
		printf("%c", moves->first);
		printf("%c", moves->second);
		if (moves->third != ' ')
			printf("%c", moves->third);
		printf("\n");
		moves = moves->next;
		n++;
	}
	printf("print_moves DONE ; %d moves\n", n-1);
}

int	nb_moves(t_move *move)
{
	int	nb;

	nb = 0;
	while (move)
	{
		nb++;
		move = move->next;
	}
	return (nb);
}
*/