#include "push_swap.h"

void	blanks(char *s, int *i)
{
	while (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13))
		(*i)++;
}

void	signs(char *s, int *i, long long *neg)
{
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*neg *= -1;
		(*i)++;
	}
}

void	zeros(char *s, int *i)
{
	while (s[*i] == '0')
		(*i)++;
}

void	nb_from_string(char *s, int *i, long long *nb)
{
	int	len_nb;

	len_nb = 0;
	while (s[*i] >= '0' && s[*i] <= '9' && len_nb <= 10)
	{
		(*nb) = (*nb) * 10 + (s[*i] - 48);
		len_nb++;
		(*i)++;
	}
}

int	ft_atoi_push_swap(char *s)
{
	int			i;
	long long	neg;
	long long	nb;
	

	neg = 1;
	nb = 0;
	i = 0;
	if (!s[i])
		return (EXIT_FAILURE);
	blanks(s, &i);
	signs(s, &i, &neg);
	zeros(s, &i);
	nb_from_string(s, &i, &nb);
	if (s[i])
		return (EXIT_FAILURE);
	nb *= neg;
	if (nb >= -2147483648 && nb <= 2147483647)
		return ((int)nb);
	return (EXIT_FAILURE);
}

//à n'appeler qu'une fois le tableau constitué
int	every_nb_single(int *array, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (array[i] == array[j])
				return (0);
		}
	}
	return (1);
}

int	main()
{
	char s[] = "";
	printf("%d\n", ft_atoi_push_swap(s));
	return (0);
}
