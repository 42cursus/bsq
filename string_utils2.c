/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
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

void	ft_putstr_std_err(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
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
