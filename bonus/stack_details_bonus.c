/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_details_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:15:50 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 19:17:18 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_stack_backlinks(t_stack *stack)
{
	int		i;
	t_stack	*precedent;

	stack->precedent = NULL;
	if (len_stack(stack) == 1)
	{
		stack->precedent = NULL;
		stack->next = NULL;
		return ;
	}
	precedent = stack;
	i = -1;
	while (stack && ++i >= 0)
	{
		if (i)
		{
			stack->precedent = precedent;
			precedent = stack;
		}
		stack = stack->next;
	}
}

/*
-----Inutile pour le rendu-----
void	show_stack_details(t_stack *stack)
{
	printf("-------------\n");
	while (stack)
	{
		printf("stack->nb = %d  stack->index = %d\n", stack->nb, stack->index);
		printf("stack->index_max = %d\n", stack->index_max);
		stack = stack->next;
	}
	printf("-------------\n");
}

char *spaces(int nb)
{
    char *blanks;
    int i;

    i = -1;
    blanks = malloc(sizeof(char) * (nb + 1));
    if (!blanks)
        return (NULL);
    while (++i < nb)
        blanks[i] = ' ';
    blanks[nb] = '\0';
    return (blanks);
}

void    show_abs(t_stack *a, t_stack *b, t_stack *s, int len)
{
    int len_a;
    int len_b;

    len_a = len_stack(a);
    len_b = len_stack(b);
    printf("----------------------------------------------\n");
    while (s)
    {
        if (len_a == len)
        {
            printf("%d%s", a->index, spaces(a->spaces));
			// remplace provisoirement par index
            len_a--;
            a = a->next;
        }
        else
            printf("               ");
        if (len_b == len)
        {
            printf("%d%s", b->index, spaces(b->spaces));
			// remplace provisoirement par index
            len_b--;
            b = b->next;
        }
        else
            printf("               ");
        printf("%d\n", s->index); // remplace provisoirement par index
        len--;
        s = s->next;
    }
    printf("a              b              s\n");
    printf("----------------------------------------------\n");
}
*/