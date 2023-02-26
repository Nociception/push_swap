/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:57:33 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/12 18:41:37 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	size_t	i;

	i = -1;
	while (++i < length && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main(int ac, char *av[])
{
	printf("%d\n",ft_strncmp("test\200", "test\300", 6));
	printf("%d\n",strncmp("test\200", "test\300", 6));
	if (ac == 1)
		printf("\ns1 s2 length");
	else
	{
		char *s1 = av[1];
		char *s2 = av[2];
		size_t length = (size_t)av[3];
		int cn = strncmp(s1, s2, length);
		int cp = ft_strncmp(s1, s2, length);
		if (1)
		{
			printf("cn = %d\n", cn);
			printf("cp = %d\n", cp);
		}
		printf("%d",ft_strncmp("test\200", "test\0", 6));
	}
	return 0;
}
*/
