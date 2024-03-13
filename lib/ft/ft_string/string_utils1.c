/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:05:47 by abelov            #+#    #+#             */
/*   Updated: 2024/03/12 18:17:51 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

/**
 * Copy src to dest, truncating or null-padding to always copy n bytes.
 * Return dest.
 * If there is no terminating null byte in the first n bytes of src, strncpy()
 * produces an unterminated string in dest.
 * `const char*` is a mutable pointer to an immutable character/string.
 * You cannot change the contents of the location(s) this pointer points to.
 */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	const char		*s = src;
	char *const		save_pointer = dest;
	unsigned int	i;

	i = 0;
	while (*s && (i++ < n))
		*dest++ = *s++;
	while (i++ < n)
		*dest++ = g_ascii_zero_character;
	return (save_pointer);
}

int	ft_strlen(char *str)
{
	const char	*ostr = str;

	while (*str)
		str++;
	return (str - ostr);
}

/**
 * Compares s1 and s2, returning less than, equal to or greater than zero
 * if s1 is lexicographically less than, equal to or greater than s2.
 */
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}

char	*ft_strcpy(char *dest, char *src)
{
	char *const	save = dest;

	while (*src)
		*dest++ = *src++;
	*dest = g_ascii_zero_character;
	return (save);
}

/**
 * The ft_strcat() function  appends  the src string to the dest string,
 * overwriting the terminating null byte ('\0') at the end of dest,
 * and then adds a terminating null byte. The strings may not overlap,
 * and the dest string must have enough space for the result.
 *
 * Returns a pointer to the resulting string dest.
 */
char	*ft_strcat(char *dest, char *src)
{
	char *const	save = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = g_ascii_zero_character;
	return (save);
}
