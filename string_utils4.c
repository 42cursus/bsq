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

void	*ft_recallocarray(void *ptr,
	size_t oldnmemb, size_t newnmemb, size_t size)
{
	size_t	oldsize;
	size_t	newsize;
	void	*newptr;
	size_t	d;

	oldsize = 0;
	newsize = 0;
	if ((newnmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW)
		&& newnmemb > 0 && SIZE_MAX / newnmemb < size)
		return (NULL);
	newsize = newnmemb * size;
	if ((oldnmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW)
		&& oldnmemb > 0 && SIZE_MAX / oldnmemb < size)
		return (NULL);
	oldsize = oldnmemb * size;
	if (newsize <= oldsize)
	{
		d = oldsize - newsize;
		if (d < oldsize / 2 && d < (size_t)getpagesize())
		{
			ft_memset((char *)ptr + newsize, 0, d);
			return (ptr);
		}
	}
	newptr = (char *)ft_memset(
			malloc((newsize) * sizeof(char)), '\0', newsize);
	if (newptr == NULL)
		return (NULL);
	if (ptr == NULL)
		return (newptr);
	if (newsize > oldsize)
	{
		ft_strncpy(newptr, ptr, oldsize);
		ft_memset((char *)newptr + oldsize, 0, newsize - oldsize);
	}
	else
		ft_strncpy(newptr, ptr, newsize);
	free(ptr);
	return (newptr);
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
