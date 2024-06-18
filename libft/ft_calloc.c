/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:28:53 by nstoutze          #+#    #+#             */
/*   Updated: 2024/06/18 01:53:05 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t	frac;

	if (count)
	{
		frac = SIZE_MAX / count;
		if (size > frac)
			return (NULL);
	}
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
/*
int main(void)
{
	return 0;
}
// count * size <= SIZE_MAX
// il faut donc que : size <= SIZE_MAX / count
// Attention : count doit etre != 0
*/
