/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:23:43 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/21 17:00:47 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_words_in_str(const char *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = -1;
	if (!s[0])
		return (0);
	if (s[++i] != c)
		nb++;
	while (s[++i])
	{
		if (s[i] != c && s[i - 1] == c)
			nb++;
	}
	return (nb);
}

static char	*next_word(const char *s, int *ptr_i, char c)
{
	char	*word;
	int		len_word;

	len_word = 0;
	while (s[*ptr_i] == c)
		(*ptr_i)++;
	while (s[*ptr_i + len_word] && s[*ptr_i + len_word] != c)
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	word[len_word] = '\0';
	len_word = 0;
	while (s[*ptr_i] && s[*ptr_i] != c)
	{
		word[len_word] = s[*ptr_i];
		len_word++;
		(*ptr_i)++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		nb_words;
	int		num_word;
	int		i;

	if (!s)
		return (NULL);
	nb_words = nb_words_in_str(s, c);
	num_word = -1;
	i = 0;
	split = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!(split))
		return (NULL);
	split[nb_words] = NULL;
	while (++num_word < nb_words)
		split[num_word] = next_word(s, &i, c);
	return (split);
}
/*
#include <stdio.h>
int main()
{
	char c = ' ';
    char s[] = "   Salut ca va ?    Ouais et toi ? Oklm    ";
    //char s[] = "hello";
    //char s[] = " hello";
    //char s[] = " hello ";
    //char s[] = "hello ";
    //char s[] = "";
	//char s[] = "\0aa\0bbb";
    int n = nb_words_in_str(s, c);
	printf("Nombre de mots : %d\n", n);
    
	char **tab = ft_split(s, c);
	int i = -1;
	printf("[");
	while (++i < n)
    {
        printf("%s", tab[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
    return (0);	
}
*/
