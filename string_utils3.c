/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:06:06 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 23:06:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

/*
 * The ft_strlcpy() function copies up to size - 1 characters
 * from the NUL-terminated string src to dst, NUL-terminating the result.
 * Returns the total length of the string tried to create (the length of src).
 * Return count does not include NUL character.
 * If retval >= dsize, truncation occurred.
 */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	const char	*save = src;

	if (size > 0)
	{
		while (size-- > 1 && *src)
			*dest++ = *src++;
		*dest = g_ascii_zero_character;
	}
	while (*src)
		src++;
	return (src - save);
}

/*
 *  The ft_strlcat() function concatenates strings. It take the full size of
 *  the buffer (not just the length) and guarantees to NUL-terminate the result
 *  (as long as there is at least one byte free in dst).
 *  ft_strlcat() only operate on true “C” strings.  This means that both src
 *  and dst must be NUL-terminated.
 *
 *  Returns the total length of the string tried to create.
 *  That means the initial length of dst plus the length of src.
 */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char *const		odest = dest;
	unsigned int	dest_len;

	while (*dest)
		dest++;
	dest_len = dest - odest;
	if (dest_len >= size)
		return (size + ft_strlen(src));
	return (dest_len + ft_strlcpy(dest, src, size - dest_len));
}

/*
 * This is sqrt(SIZE_MAX+1), as s1*s2 <= SIZE_MAX
 * if both s1 < MUL_NO_OVERFLOW and s2 < MUL_NO_OVERFLOW
 */
#define MUL_NO_OVERFLOW ((size_t)1 << (sizeof(size_t) * 4))

int	getpagesize(void)
{
	return (PAGESIZE);
}

//TODO:	use ft_memset(ptr,0, oldsize); before free
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
