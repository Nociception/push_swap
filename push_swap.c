/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:56:29 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/11 23:56:29 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_data(int len, char *av[])
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (!ft_atoi_push_swap(av[i + 1]))
			return (0);
	}
	return (1);
}

void	push_swap(int ac, char *av[])
{
	int		*array;
	int		*sorted;
	t_stack	*a;
	t_stack	*b;
	t_stack	*s;

	a = NULL;
	b = NULL;
	s = NULL;
	array = fill_array_with_valid_data(ac - 1, av);
	if (are_numbers_unique(array, ac - 1))
	{
		sorted = sort_array(array, ac - 1);
		a = array_to_stack(array, ac - 1);
		s = array_to_stack(sorted, ac - 1);
		add_stack_backlinks(a);
		index_on_s(s, ac - 1);
		index_on_a(a, s);
		algo_length(&a, &b, s, ac - 1);
	}
	else
		ft_putstr_fd("Error\n", 0);
}

int	main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (valid_data(ac - 1, av))
			push_swap(ac, av);
		else
			ft_putstr_fd("Error\n", 0);
	}
	return (0);
}

/*
virer les tester pour le rendu

verifier les leaks
reprendre janitor pour remplacer les free

Norme (variable et noms de fichiers -> lettre majuscule ; headers)

bonus : checker

stocker les mouvements dans une liste chainee pour ensuite l'optimiser/ecremer
*/