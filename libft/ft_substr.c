/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:42:17 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 16:55:02 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((size_t)start >= slen)
		return (ft_strdup("\0"));
	if (slen - (size_t)start > len)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else
		sub = (char *)malloc(sizeof(char) * (slen - (size_t)start + 1));
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < len && s[start])
	{
		sub[i] = s[start];
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>
int main()
{
	const char str[] = "tripouille";
	printf("ft_strlen(str) = %lu\n", ft_strlen(str));
	unsigned int start = 1;
	size_t len = 1;
	char *s = ft_substr(str, start, len);
	printf("%s\n", s);
	return 0;
}

printf("begining = %ld, i = %ld, s[begining] = %c\n", begining, i, s[begining]);

sub = (char *)malloc(sizeof(char) * (slen - (size_t)start + 1));

char* ft_substr(char const* s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char* sub;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	long	i;
	long	begining;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	begining = (long)start - 1;
	if (!sub || !s || (size_t)start >= ft_strlen(s))
		return (NULL);
	while (s[++begining] && ++i < (long)len)
		sub[i] = s[begining];
	sub[i + 1] = '\0';
	return (sub);
}
*/
