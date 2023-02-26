/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:37:48 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/20 18:52:05 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*
int ft_lstsize(t_list *lst)
{
	int	size; 

	size = 0; //Si le if precedent n'a pas servi, le premier elt de la liste
	// existe donc, et ladite liste est donc de longueur 1
	while (lst) //tant que le next du maillon courant
   // ne pointe pas sur null
	{
		size++;
		lst = lst->next; // le next du maillon courant
		// devient le next du prochain maillon
	}
	return (size);
}
*/
