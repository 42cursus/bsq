/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:25:26 by abelov            #+#    #+#             */
/*   Updated: 2023/10/25 20:25:29 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

void	*allocate_and_copy_data(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	char	*dst;

	new_ptr = (char *)ft_memset(malloc(new_size), '\0', new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		ft_strncpy(new_ptr, ptr, old_size);
		if (new_size > old_size)
		{
			dst = (char *) new_ptr + old_size;
			ft_memset(dst, 0, new_size - old_size);
		}
	}
	return (new_ptr);
}

void	*ft_recallocarray(void *ptr,
	size_t oldnmemb, size_t newnmemb, size_t size)
{
	void	*new_ptr;
	size_t	new_size;

	new_size = 0;
	if (newnmemb == oldnmemb)
		return (ptr);
	else if (newnmemb > oldnmemb)
		new_size = (newnmemb * size);
	else
		new_size = (oldnmemb * size);
	new_ptr = allocate_and_copy_data(ptr, oldnmemb * size, new_size);
	if (new_ptr == NULL)
		return (NULL);
	free(ptr);
	return (new_ptr);
}
