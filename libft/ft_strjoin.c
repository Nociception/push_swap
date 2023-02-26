/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:06:44 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/17 18:06:17 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	total_size;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(sizeof(char) * total_size);
	if (!join)
		return (NULL);
	while (++i < ft_strlen(s1))
		join[i] = s1[i];
	while (++j < ft_strlen(s2))
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return (join);
}
/*
#include <stdio.h>
int	main()
{
	char s1[] = "salut,";
	char s2[] = " ca va ?";
	printf("%s\n", ft_strjoin(s1, s2));
	return 0;
}
*/
