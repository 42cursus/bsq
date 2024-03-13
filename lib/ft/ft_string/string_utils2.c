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
