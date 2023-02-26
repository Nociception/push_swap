/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:51:07 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/20 16:38:06 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
	}
}
/*
void	ft_lstclear(t_list **lst, void (*del)(void*))
// on recoit un pointeur sur pointeur sur list ; et la fonction del
{
	t_list *tmp; //variable pour stocker l'element 
	//qui sera supprime a chaque iteration

	if (lst) //protection
	{
		while (*lst) //tant que l'on atteint pas le dernier elt
		{
			tmp = (*lst)->next; //stockage de l'adresse next dans tmp
			ft_lstdelone(*lst, del); // suppression de l'elt courant
			*lst = tmp; // *lst est reassigne a tmp (soit next) 
			//pour continuer le while
		}
	}
}
*/
