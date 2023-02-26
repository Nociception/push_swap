/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:47:35 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 15:34:07 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!dst && !dstsize)
		return (0);
	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	len = i + ft_strlen(src);
	while (src[j] && i + 1 < dstsize)
		dst[i++] = src[j++];
	if (dstsize > i)
		dst[i] = '\0';
	return (len);
}
/*
int main()
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    int size = 1;
    char buffer[size];

    strcpy(buffer,first);
    r = strlcat(buffer,last,size);

    puts(buffer);
	printf("first = %s\nstrlen(first) = %lu\n", first, strlen(first));
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);
}
*/
