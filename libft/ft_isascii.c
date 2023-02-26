/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:47:48 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 16:21:32 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
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
		if (isascii(i) != ft_isascii(i))
		{
			printf("ft_isascii(%d) = %d\n", i, ft_isascii(i));
			printf("isascii(%d) = %d\n", i, isascii(i));
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
