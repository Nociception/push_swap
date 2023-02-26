/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:46:28 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:11:32 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchedChar)
{
	while (*(str))
	{
		if ((unsigned char)*str == (unsigned char)searchedChar)
			return ((char *)str);
		str++;
	}
	if (!searchedChar)
		return ((char *)str);
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>
int main()
{
	const char str[] = "coucou";

	int searchedChar = 'c';
	if (strchr(str, searchedChar) == ft_strchr(str, searchedChar))
	{
		printf("%s\n", ft_strchr(str, searchedChar));
		printf("%s\n", strchr(str, searchedChar));
	}	
	return 0;
}
*/