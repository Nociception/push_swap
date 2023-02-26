/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:08:48 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/18 10:19:41 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	long long	i;
	char		*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = (*f)((unsigned int)i, s[i]);
	str[i] = '\0';
	return (str);
}
/*
char	move3(unsigned int i, char c)
{
	(void)i;
	c += 3;
	return (c);
}
#include <stdio.h>
int main()
{
	char const	s[] = "tripouille";
	char *str = ft_strmapi(s, &move3);
	printf("%s\n", str);
	return 0;
}

#include "libft.h"
#include <stdio.h>
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	long long	i;
	char		*str;
	char		*string;

	string = ft_strdup(s);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (string[++i])
	{
		printf("Avant : str[i] = %c\n", str[i]);
		str[i] = (*f)((unsigned int)i, string[i]);
		printf("Apres : str[i] = %c\n", str[i]);
	}
	return (str);
}
*/
