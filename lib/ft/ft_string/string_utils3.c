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

/**
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

/**
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

int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_printable(char c)
{
	return (!(c < g_ascii_space_character || c == g_ascii_del_character));
}

/**
 * The  ft_strncat() function  appends at most n bytes from src string to
 * the dest string, overwriting the terminating null byte ('\0') at the end
 * of dest, and then adds a terminating null byte. The strings may not overlap,
 * and the dest string must have enough space for the result. The src does not
 * need to be null-terminated if it contains n or more bytes.
 * The resulting string in dest is always null-terminated.
 * If  src  contains  n or more bytes, strncat() writes n+1 bytes to dest
 * (n from src plus the terminating null byte).
 * Therefore, the size of dest must be at least strlen(dest)+n+1.
 */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *const		save_pointer = dest;
	unsigned int	i;

	i = 0;
	while (*dest)
		dest++;
	while (*src && (i++ < nb))
		*dest++ = *src++;
	*dest = g_ascii_zero_character;
	return (save_pointer);
}
