/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberezhn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:02:46 by yberezhn          #+#    #+#             */
/*   Updated: 2023/10/25 17:31:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_sq_element	*alloc_empty_map(int size)
{
	t_sq_element	*map;

	map = malloc(sizeof(t_sq_element) * size);
	if (!map)
		return (NULL);
	ft_memset(map, 0, sizeof(t_sq_element) * size);
	return (map);
}
