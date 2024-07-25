/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/26 01:51:11 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;
	char		*tmp;
	ssize_t		nl;

	line = NULL;
	if (fd >= 0 && read(fd, NULL, 0) != -1 && BUFFER_SIZE > 0)
	{
		nl = newline_seeker(read_a_line(fd, &line, &remainder)) + 1;
		if (nl >= 1 && (size_t)nl <= ft_stlen(line))
		{
			tmp = line;
			remainder = ft_join(remainder, line + nl, ft_stlen(line) - nl);
			line = ft_join(0, line, nl);
			free(tmp);
		}
		if (line)
			return (line);
	}
	free(remainder);
	remainder = NULL;
	return (line);
}

char	*read_a_line(int fd, char **line, char **rmd)
{
	ssize_t	b_len;

	if (*rmd)
	{
		if (ft_stlen(*rmd) > 0)
			*line = ft_join(0, *rmd, ft_stlen(*rmd));
		free(*rmd);
		*rmd = NULL;
	}
	while (42)
	{
		*line = join_the_buf(fd, *line, &b_len);
		if (newline_seeker(*line) >= 0)
			break ;
		if (b_len == BUFFER_SIZE)
			continue ;
		if (b_len < 0)
			free(*line);
		break ;
	}
	return (*line);
}

char	*join_the_buf(int fd, char *line, ssize_t *b_len)
{
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
	{
		free(line);
		return (0);
	}
	*b_len = read(fd, buf, BUFFER_SIZE);
	if (*b_len > 0)
	{
		tmp = line;
		line = ft_join(line, buf, *b_len);
		free(tmp);
	}
	free(buf);
	return (line);
}

ssize_t	newline_seeker(char *s)
{
	size_t	idx;

	idx = 0;
	if (!s)
		return (-1);
	while (*(s + idx))
	{
		if (*(s + idx) == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}
