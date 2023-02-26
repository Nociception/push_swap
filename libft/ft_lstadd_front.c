/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:19:55 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/20 17:09:12 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new -> next = *lst;
	*lst = new;
}
/*
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)	// Si le premier elt de la liste existe
		new -> next = *lst; //le next du nouvel element 
							//pointe sur le premier elt de lst
	*lst = new; // Dans tous les cas, le premier elt de lst est new
}
*/
