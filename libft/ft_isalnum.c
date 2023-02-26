/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:39:21 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 16:20:08 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isdigit(c) || ft_isalpha(c)));
}
/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
	int i = -1;
	int d = 0;
	while (++i <= 127)
	{
		if (isalnum(i) != ft_isalnum(i))
		{
			printf("ft_isalnum(%d) = %d\n", i, ft_isalnum(i));
			printf("isalnum(%d) = %d\n", i, isalnum(i));
			d++;
		}
	}
	if (d)
		printf("Nombre de differences : %d\n", d);
	else
		printf("Bingo ! Aucune difference !\n");
	return (0);
}
*/
