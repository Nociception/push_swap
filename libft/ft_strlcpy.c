/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:27:27 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 18:50:02 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = -1;
	if (size > 0)
	{
		while (src[++i] && --size)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
void test(int size)
{
    char string[] = "salut";
    char *buffer = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
    char *BUFFER = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
    int r;
	int R;

    r = strlcpy(buffer,string,size);
	R = ft_strlcpy(BUFFER,string,size);
}

int main()
{
    test(19);
    test(10);
    test(1);
    test(0);

    return(0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	long long	i;

	i = -1;
	while (++i < (long long)dstsize - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
*/
