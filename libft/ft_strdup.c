/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:35 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/13 19:14:21 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(s);
	i = -1;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (++i < len)
		dup[i] = s[i];
	dup[len] = '\0';
	return (dup);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	const char *s = "salut";
	printf("%s\n", ft_strdup(s));
	return 0;
}
*/
