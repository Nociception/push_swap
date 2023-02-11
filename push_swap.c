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
/*
REGLER LE PROBLEME DU 11 QUI N'EST PAS PLUS A LA FIN DE PART_ONE

retravailler l'algo 6 avant d'entamer l'algo principal
une pile de contenant entre 7 et 13 (inclus) elements provoque une segfault ; 58 54 39 35 78 98 47
Les piles de 0 a 6 passent, de meme que les piles contenant plus de 14 (inclus)

Norme (variable lettre majuscule)
headers
Bonus : checker
include printf
parsing (nb uniques notamment)
structure englobante (notamment pour compter le nombre de moves)

ajouter une data a la structure t_stack pour generer un indice de circonstance
OU
jouer sur l'indice max

free les targets perdantes

stocker les les mouvements dans une liste chainee pour ensuite l'optimiser/ecremer

Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre
l’invite de commande.

En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
un int, ou encore, s’il y a des doublons.
*/

void testing_random_moves(t_stack **a, t_stack **b)
{
	push_b(a, b);
	push_b(a, b);
	push_a(a, b);
	push_b(a, b);
	push_b(a, b);
	push_a(a, b);
	push_b(a, b);
	rotate_a(a, *b);
	rotate_a(a, *b);
	rotate_a(a, *b);
	rotate_b(*a, b);
	rotate_b(*a, b);
	rotate_b(*a, b);
	reverserotate_a(a, *b);
	reverserotate_a(a, *b);
	reverserotate_a(a, *b);
	reverserotate_a(a, *b);
	reverserotate_b(*a, b);
	reverserotate_b(*a, b);
	reverserotate_b(*a, b);
	swap_a(a, *b);
	swap_b(*a, b);
}

int main(int ac, char *av[])
{
    int *array;
    int *sorted;
    int len;
    t_stack *a;
    t_stack *b;
    t_stack *s;

    len = ac - 1;
    a = NULL;
    b = NULL;
    s = NULL;
    if (ac > 1)
    {
        array = retrieve_data(len, av);
        sorted = sort_array(array, len);
        a = array_to_stack(array, len);
        s = array_to_stack(sorted, len);
        add_stack_backlinks(a);
        index_on_s(s, len);
        index_on_a(a, s);

		show_abs(a, b, s, len);

		//testing_random_moves(&a, &b);
		algo_length(&a, &b, s, len);
        
		show_abs(a, b, s, len);
    }
    printf("MAIN : -----------------------------------\n");
    printf("MAIN : traitement termine\n");
	//print_moves(a, b);
    if (sorted_final_stack_ontop(a))
            printf("MAIN : STACK SORTED !!!\n");
        else
            printf("MAIN : Stack not sorted :( :( :(\n");
    printf("MAIN : return (0) imminent ; AUCUN CRASH\n");
    return (0);
}