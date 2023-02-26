/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:56:15 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/17 20:15:34 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	long long	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			(*f)((unsigned int)i, s + (unsigned int)i);
	}
}
/*
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	long long	i;

	i = -1;
	if (s)
	{
		while (s[++i])
		{
			printf("%lld\n", i);
			(*f)((unsigned int)i, s + (unsigned int)i);
		}
	}
}

void	move3(unsigned int i, char *s)
{
	printf("Avant traitement : s[i] = %c\n", *s);
	*s += 3 - i;
	printf("Apres traitement : s[i] = %c\n", *s);
}
#include <stdio.h>
int main()
{
	char	s[] = "tripouille";
	ft_striteri(s, &move3);
	printf("%s\n", s);
	return 0;
}
*/
