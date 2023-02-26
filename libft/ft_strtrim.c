/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:14:20 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/17 17:06:21 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && (ft_strchr(set, s1[i])))
		i++;
	if (i == j + 1)
		return (ft_strdup("\0"));
	while (s1[j] && (ft_strrchr(set, s1[j])))
		j--;
	size = j - i + 1;
	str = ft_substr(s1, (unsigned int)i, (size_t)size);
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char s[] = "  ?   salut  ?  ";
	char set[] = " ?";
	printf("%s\n", ft_strtrim(s, set));
	return 0;
}
*/
