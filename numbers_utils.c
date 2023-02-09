/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:25:53 by nstoutze          #+#    #+#             */
/*   Updated: 2023/01/29 15:25:53 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(char *s)
{
    int n;
    int i;
	int neg;

    n = 0;
    i = -1;
	neg = 1;
	if (s[0] == '-' || s[0] == '+')
	{
		i++;
		if (s[0] == '-')
			neg = -1;
	}
    while(s[++i])
    {
        n *= 10;
        n += s[i] - 48;
    }
    return (n * neg);
}

int len_int(int nb)
{
    int len;

    len = 0;
    if (!nb)
        return (1);
    if (nb < 0)
    {
        nb = -nb;
        len++;
    }
    while (nb)
    {
        len++;
        nb /= 10;
    }
    return (len);
}

int	abs_val(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

void	swap_int(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	ft_max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

int	mean_two_positive_numbers(int x, int y)
{
	return ((x + y) / 2);
}