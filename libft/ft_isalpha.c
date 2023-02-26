/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:05:53 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 16:20:56 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
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
		if (isalpha(i) != ft_isalpha(i))
		{
			printf("ft_isalpha(%d) = %d\n", i, ft_isalpha(i));
			printf("isalpha(%d) = %d\n", i, isalpha(i));
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
