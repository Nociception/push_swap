/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:45 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:10:44 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[] = "LIGNE 1 contenu ahah longueur encore toujours constance";
	printf("str[] = \"%s\"\n", str);
	printf("Longueur selon ft_strlen(str) : %lu\n", ft_strlen(str));
	printf("Longueur selon strlen(str) : %lu\n\n", strlen(str));
	
	char STR[] = "LIGNE 1 contenu ahah";
	printf("STR[] = \"%s\"\n", STR);
	printf("Longueur selon ft_strlen(STR) : %lu\n", ft_strlen(STR));
	printf("Longueur selon strlen(STR) : %lu\n\n", strlen(STR));
	return (0);
}
*/