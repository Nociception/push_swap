/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:05:21 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:14:27 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(char *s);
char	*gnl_strchr(char *str, int searchedChar);
size_t	gnl_strlen(char *s);

#endif
