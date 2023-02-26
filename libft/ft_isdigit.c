/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:34:03 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 16:22:04 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
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
		if (isdigit(i) != ft_isdigit(i))
		{
			printf("ft_isdigit(%d) = %d\n", i, ft_isdigit(i));
			printf("isdigit(%d) = %d\n", i, isdigit(i));
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
