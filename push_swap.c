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

void	push_swap(int len, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*s;

	a = NULL;
	b = NULL;
	s = NULL;
	feed_stacks(len, av, &a, &s);
	algo_length(&a, &b, s, abs_val(len));
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
			push_swap(len, arg);
		else
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}

/*
system("leaks push_swap >&2");

cp ../../push_swap/generator.py
LST=$(./generator.py 10)
./push_swap ${=LST}
./push_swap ${=LST} | ./checker_Mac ${=LST}

Bonus :
./push_swap ${=LST} | ./checker ${=LST}



gerer les guillemets avec un seul argument en entree
	Reception du char**
	si ac == 2
		str = split de av[1]




Norme :
	DONE partie obligatoire
	DONE partie bonus

ABANDONED stocker les mouvements dans une liste chainee pour 
ensuite l'optimiser/ecremer
*/

/*
Operations preliminaires anciennement directement dans la fonction push_swap
	//int		*array;
	//int		*sorted;
	array = fill_array_with_valid_data(ac - 1, av);
	if (are_numbers_unique(array, ac - 1))
	{
		sorted = sort_array(array, ac - 1);
		a = array_to_stack(array, ac - 1);
		s = array_to_stack(sorted, ac - 1);
		add_stack_backlinks(a);
		index_on_s(s, ac - 1);
		index_on_a(a, s);
	}
	else
		ft_putstr_fd("Error\n", 2);
	janitor(array);
	janitor(sorted);
*/