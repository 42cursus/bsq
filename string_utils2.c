/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:32:21 by abelov            #+#    #+#             */
/*   Updated: 2023/10/22 22:32:22 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "string_utils.h"

void	ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

char	*ft_strdup(char *src)
{
	char	*new;

	new = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	return (ft_strcpy(new, src));
}

char	*ft_empty_string(int length)
{
	char			*new;
	unsigned char	*ptr;

	new = (char *)malloc(sizeof(char) * length + 1);
	if (!new)
		return (NULL);
	ptr = (unsigned char *)new;
	while (length-- >= 0)
		*ptr++ = '\0';
	return (new);
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