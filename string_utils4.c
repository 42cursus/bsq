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

#include <stdbool.h>
#include "string_utils.h"

static inline bool	check_buf_size(size_t memb, size_t size)
{
	return ((memb >= ((size_t) 1 << (sizeof(size_t) * 4)) || size >= ((size_t) 1
				<< (sizeof(size_t) * 4)))
		&& memb > 0 && SIZE_MAX / memb < size);
}

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
	size_t	old_size;
	size_t	new_size;
	void	*new_ptr;
	size_t	d;

	old_size = 0;
	new_size = 0;
	if (check_buf_size(newnmemb, size))
		return (NULL);
	new_size = newnmemb * size;
	if (check_buf_size(oldnmemb, size))
		return (NULL);
	old_size = oldnmemb * size;
	if (new_size <= old_size)
	{
		d = old_size - new_size;
		if (d < old_size / 2 && d < (size_t)PAGESIZE)
		{
			ft_memset((char *)ptr + new_size, 0, d);
			return (ptr);
		}
	}
	new_ptr = (char *)ft_memset(
			malloc((new_size) * sizeof(char)), '\0', new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr == NULL)
		return (new_ptr);
	if (new_size > old_size)
	{
		ft_strncpy(new_ptr, ptr, old_size);
		ft_memset((char *)new_ptr + old_size, 0, new_size - old_size);
	}
	else
		ft_strncpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
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
