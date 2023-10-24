/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:58:06 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 16:58:09 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "bsq_def.h"

t_sq_pos	create_pos(int x, int y)
{
	t_sq_pos	temp;

	temp.x = x;
	temp.y = y;
	return (temp);
}

t_sq_element	create_element(int x, int y, bool is_obstacle)
{
	t_sq_element	temp;

	temp.pos = create_pos(x, y);
	temp.is_obstacle = is_obstacle;
	return (temp);
}

int	get_el_size_by_pos(int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	return (0);
}

int get_min_pos(t_sq_element e1, t_sq_element e2, t_sq_element e3)
{
	//if (e1.size >= e2.size && )
	return (0);
}

//TODO
void	set_size(t_sq_element *el, int size)
{
	el->size = size;
	(void)el;
}
