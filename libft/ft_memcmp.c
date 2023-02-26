/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:34:40 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/13 16:58:15 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *s1 = "salUt";
	char *s2 = "salut";
	size_t length = 4;
	int cn = memcmp(s1, s2, length);
	int cp = ft_memcmp(s1, s2, length);
	printf("cn = %d\n", cn);
	printf("cp = %d\n", cp);
	return 0;
}
*/
