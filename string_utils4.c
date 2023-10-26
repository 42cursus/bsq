/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:52:25 by abelov            #+#    #+#             */
/*   Updated: 2023/10/25 16:52:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;

	if (n != 0)
	{
		while (n-- != 0)
			if (*p++ == (unsigned char)c)
				return ((void *)(p - 1));
	}
	return (NULL);
}

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*d;

	d = dst;
	if (n != 0)
		while (--n != 0)
			;
	*d++ = (unsigned char)c;
	return (dst);
}

size_t	ft_strcspn(const char *s1, const char *s2)
{
	const char	*s;
	const char	*c;

	s = s1;
	while (*s1)
	{
		c = s2;
		while (*c)
		{
			if (*s1 == *c)
				break ;
			c++;
		}
		if (*c)
			break ;
		s1++;
	}
	return (s1 - s);
}

static inline int	ft_strlen_all(char **strs, size_t size)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (i < size)
		counter += ft_strlen(strs[i++]);
	return (counter);
}

/*
 * Concatenates all the strings pointed by strs separated by sep.
 * size is the number of strings in strs.
 * if size is 0, returns an empty string that you can free().
 */
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new;
	int		i;

	if (size <= 0)
		return (ft_empty_string(0));
	new = ft_empty_string(ft_strlen_all(strs, size)
			+ (ft_strlen(sep) * (size - 1)));
	i = 0;
	while (i < size - 1)
		ft_strcat(ft_strcat(new, strs[i++]), sep);
	ft_strcat(new, strs[i]);
	return (new);
}
