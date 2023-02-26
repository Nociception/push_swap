/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:22:31 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 17:40:47 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (!ptr_dst && !ptr_src)
		return (NULL);
	if (ptr_src < ptr_dst)
	{
		while (++i <= len)
			ptr_dst[len - i] = ptr_src[len - i];
	}
	else
	{
		while (len-- > 0)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src[] = "salut";
	char *DsT = malloc(sizeof(ft_strlen(src)) + 1);
	ft_memmove(DsT, src, 11);
	printf("%s\n", DsT);
	return 0;
}
*/
