/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:18:58 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 18:39:04 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	int		i;
	char	*s;

	if (!searchedChar)
		return ((char *)(str + ft_strlen(str)));
	i = ft_strlen(str) + 1;
	s = (char *)str + ft_strlen(str);
	while (--i)
	{
		s--;
		if ((unsigned char)*s == (unsigned char)searchedChar)
			return (s);
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	const char s[] = "Salut";
	int c = '\0';
	if (strrchr(s, c) != ft_strrchr(s, c))
	{
		printf("%s\n", strrchr(s, c));
		printf("%s\n", ft_strrchr(s, c));
	}
	const char str[] = "tripouille";
	printf("%s\n", ft_strrchr(str, 't' + 256));
	printf("%s\n", strrchr(str, 't' + 256));

	const char str2[] = "bonjour";
	printf("%s\n", ft_strrchr(str2, 's'));
	printf("%s\n", strrchr(str2, 's'));
	return 0;
}
*/
