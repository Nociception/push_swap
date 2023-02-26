/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:50:13 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/17 16:05:33 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_int(long long n)
{
	long long	i;
	long long	d;

	i = 0;
	d = 10;
	while (n / d)
	{
		i++;
		d *= 10;
	}
	return (i + 1);
}

static int	pow(long long nb, long long power)
{
	long long	i;
	long long	b;

	i = 0;
	b = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power - 1)
	{
		nb *= b;
		i++;
	}
	return (nb);
}

static char	*strset_for_itoa(long long *m,
		long long *len, long long *i, char *ascii)
{
	long long	trash;

	*len = len_int(*m);
	if (*m < 0)
		(*len)++;
	ascii = (char *)malloc(sizeof(char) * (*len + 1));
	if (!ascii)
		return (0);
	ascii[*len] = '\0';
	*i = 0;
	if (*m < 0)
	{
		ascii[0] = '-';
		(*len)--;
		(*i)++;
		*m *= -1;
	}
	trash = *len + *i;
	return (ascii);
}

char	*ft_itoa(int n)
{
	char		*ascii;
	long long	len;
	long long	i;
	long long	h;
	long long	m;

	m = (long long)n;
	ascii = "0";
	ascii = strset_for_itoa(&m, &len, &i, ascii);
	if (!ascii)
		return (0);
	while (len--)
	{
		h = m / pow(10, len);
		ascii[i] = h + '0';
		m -= h * pow(10, len);
		i++;
	}
	return (ascii);
}
/*
#include <stdio.h>
int main()
{
	int n = 5;
	printf("%s\n", ft_itoa(n));
	return 0;
}
*/
