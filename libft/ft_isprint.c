/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:06:00 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 16:22:43 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
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
		if (isprint(i) != ft_isprint(i))
		{
			printf("ft_isprint(%d) = %d\n", i, ft_isprint(i));
			printf("isprint(%d) = %d\n", i, isprint(i));
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
