/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:27:48 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 16:13:58 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *b, size_t len)
{
	long long		i;
	unsigned char	*str;

	i = -1;
	str = b;
	while (++i < (long long)len)
		str[i] = 0;
	return (b);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{	
	char str[10];
	int i = -1;
	printf("str avant bzero : \n");
	while (++i < 10)
		printf("%d", str[i]);
	printf("\n");
	bzero(str, 10);
	i = -1;
	printf("str apres bzero : \n");
	while (++i < 10)
		printf("%d", str[i]);
	
	printf("\n");
	char STR[10];
	i = -1;
	printf("STR avant ft_bzero : \n");
	while (++i < 10)
		printf("%d", STR[i]);
	printf("\n");
	ft_bzero(STR, 10);
	i = -1;
	printf("STR apres ft_bzero : \n");
	while (++i < 10)
		printf("%d", STR[i]);
	printf("\n");
	return (0);
}
*/
