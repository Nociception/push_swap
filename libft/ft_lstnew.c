/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:50:36 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/20 19:10:01 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elt;

	elt = NULL;
	elt = (t_list *)malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}
/*
#include <stdio.h>
int main()
{
	char a[] = "lol";
	t_list *elt = ft_lstnew(&a);
	printf("content : %s ; next : %p\n", (char *)(elt->content), elt->next);
	return 0;
}
*/
