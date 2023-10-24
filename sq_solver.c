/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sq_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:06:23 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 17:06:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sq_utils.h"



void	fill_all_sizes(t_baguette b)
{
	int	i;

	i = 0;
	while (i <= b.map_arr_length)
	{
		set_size(&b.map[i], b);
		i++;
	}
}

t_baguette	get_solution(t_baguette b)
{
	fill_all_sizes(b);
	return (b);
}

//typedef struct s_bsq_element
//{
//	struct s_sq_element	base;
//	bool				is_bsq;
//}
//
//char	*serializer(t_baguette baguette)
//{
//	(void)baguette;
//	return (NULL);
//}
//
//char	*serial_killer(t_baguette baguette)
//{
//	(void)baguette;
//	return (NULL);
//}
