/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:35:33 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:24:49 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_move(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "sa\n", 10))
		swap_a(a);
	else if (!ft_strncmp(move, "sb\n", 10))
		swap_b(b);
	else if (!ft_strncmp(move, "ss\n", 10))
		swap_both(a, b);
	else if (!ft_strncmp(move, "ra\n", 10))
		rotate_a(a);
	else if (!ft_strncmp(move, "rb\n", 10))
		rotate_b(b);
	else if (!ft_strncmp(move, "rr\n", 10))
		rotate_both(a, b);
	else if (!ft_strncmp(move, "rra\n", 10))
		reverserotate_a(a);
	else if (!ft_strncmp(move, "rrb\n", 10))
		reverserotate_b(b);
	else if (!ft_strncmp(move, "rrr\n", 10))
		reverserotate_both(a, b);
	else if (!ft_strncmp(move, "pa\n", 10))
		push_a(a, b);
	else if (!ft_strncmp(move, "pb\n", 10))
		push_b(a, b);
	else
		ft_error("Error : invalid move\n");
}

void	print_sorted_status(t_stack *a, t_stack *b)
{
	a = top_stack(a);
	if (sorted_final_stack_ontop(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	checker(int len, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*s;
	char	*move;

	a = NULL;
	b = NULL;
	s = NULL;
	move = (void *) 1;
	feed_stacks(len, av, &a, &s);
	while (move)
	{
		move = get_next_line(0);
		if (!move || !move[0])
			break ;
		do_move(&a, &b, move);
	}
	print_sorted_status(a, b);
	stack_janitor(&a, &b, &s);
}

int	main(int ac, char *av[])
{
	int		len;
	char	**arg;

	if (ac > 1)
	{
		if (ac == 2)
		{
			arg = ft_split(av[1], ' ');
			len = -(len_char_starstar_from_split(arg));
		}
		else
		{
			arg = av;
			len = ac - 1;
		}
		if (valid_data(len, arg))
			checker(len, arg);
		else
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
