/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:27:29 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/28 22:06:00 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	icis(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (i);
}

static void	janitor(char **dust)
{
	if (*dust)
	{
		free(*dust);
		*dust = NULL;
	}
}

static char	*read_fd(char *proto, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb_read_bytes;
	int		i;

	i = -1;
	while (++i <= BUFFER_SIZE)
		buffer[i] = '\0';
	nb_read_bytes = 1;
	while (!gnl_strchr(buffer, '\n') && nb_read_bytes)
	{
		nb_read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_read_bytes == -1 || (!nb_read_bytes && !proto))
		{
			janitor(&proto);
			return (0);
		}
		buffer[nb_read_bytes] = '\0';
		if (proto)
			proto = gnl_strjoin(proto, buffer);
		else
			proto = gnl_strdup(buffer);
	}
	return (proto);
}

static char	*gen_line(int fd, char *proto, char **tank)
{
	char	*line;

	line = read_fd(proto, fd);
	proto = gnl_strdup(line);
	janitor(&line);
	if (proto && gnl_strchr(proto, '\n'))
	{
		line = gnl_substr(proto, 0, icis(proto, '\n') + 1);
		if (gnl_strlen(line) != gnl_strlen(proto))
		{
			*tank = gnl_substr(proto, icis(proto, '\n') + 1, gnl_strlen(proto));
			janitor(&proto);
			return (line);
		}
		else
		{
			janitor(&line);
			return (proto);
		}
	}
	else if (proto)
		return (proto);
	janitor(&proto);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*proto;
	static char	*tank = NULL;

	proto = NULL;
	if (!tank)
		return (gen_line(fd, proto, &tank));
	else
	{
		if (gnl_strchr(tank, '\n'))
		{
			line = gnl_substr(tank, 0, icis(tank, '\n') + 1);
			proto = gnl_substr(tank, icis(tank, '\n') + 1, gnl_strlen(tank));
			janitor(&tank);
			tank = gnl_strdup(proto);
			janitor(&proto);
			return (line);
		}
		else
		{
			proto = gnl_strdup(tank);
			janitor(&tank);
			return (gen_line(fd, proto, &tank));
		}
	}
}
