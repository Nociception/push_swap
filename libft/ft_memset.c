/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:33:33 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 16:36:56 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	long long		i;
	unsigned char	*str;

	i = -1;
	str = b;
	while (++i < (long long)len)
		str[i] = (unsigned char)c;
	return (b);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	int c = 74;
	char str[100];
	int i = -1;
	while (++i < 100)
		printf("%c", str[i]);
	printf("\n");
	memset(str, c, 100);
	i = -1;
	while (++i < 100)
		printf("%c", str[i]);

	printf("\n");
	char STR[100];
	i = -1;
	while (++i < 100)
		printf("%c", STR[i]);
	printf("\n");
	ft_memset(STR, c, 100);
	i = -1;
	while (++i < 100)
		printf("%c", STR[i]);
	printf("\n");
	return (0);
}

//DESCRIPTION
//     The memset() function writes len bytes of value c 
//     (converted to an unsigned char) to the string b.
//
//RETURN VALUES
//     The memset() function returns its first argument.
*/
