/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:38 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/26 01:51:11 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_stlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_join(char *s1, char *s2, ssize_t blen)
{
	char	*new;
	ssize_t	len_s1;

	len_s1 = ft_stlen(s1);
	new = (char *)malloc(sizeof(char) * (len_s1 + blen + 1));
	if (!(new))
		return (0);
	ft_mcpy(new, s1, len_s1);
	ft_mcpy(new + len_s1, s2, blen);
	*(new + len_s1 + blen) = 0;
	return (new);
}

void	*ft_mcpy(void *dst, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;	

	d = dst;
	s = (unsigned char *)src;
	if (!d && !s)
		return (0);
	if (d < s || d >= (s + n))
	{
		while (n--)
			*(d++) = *(s++);
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dst);
}
