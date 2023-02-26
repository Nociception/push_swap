/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:44:36 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/14 16:25:12 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	w;

	i = -1;
	if (!(needle[0]))
		return ((char *)haystack);
	while (++i < n && haystack[i])
	{
		w = 0;
		while (haystack[i + w] == needle[w]
			&& haystack[i + w] && needle[w]
			&& (i + w) < n)
			w++;
		if (!(needle[w]))
			return ((char *)&haystack[i]);
		else if (!(haystack[i + w]))
			return (NULL);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char h[] = "Couaiguillecou je suis la il faut me trouver !";
	char needle[] = "aiguille";
	int n = 5;
	printf("%s\n", ft_strnstr(h, needle, n));
	printf("%s\n", strnstr(h, needle, n));
	return 0;
}
*/
