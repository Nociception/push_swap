/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:40:13 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:30 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	long long		i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (!dst && !src)
		return (NULL);
	i = -1;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (++i < (long long)n)
		ptr_dst[i] = ptr_src[i];
	return (dst);
}
/*
#include <stdio.h>
int main()
{
	char src[] = "salut";
	char *DsT = malloc(sizeof(ft_strlen(src)) + 1);
	ft_memcpy(DsT, src, 11);
	printf("%s\n", DsT);
	free(DsT);
	return 0;
}

// Erreur persistante : 
// je stoppais la boucle des qu'un \0 etait trouve, alors qu il ne fallait pas !
// The memcpy() function copies n bytes from memory area src to memory area
// dst.
*/
