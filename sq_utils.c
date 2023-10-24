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

#include "sq_utils.h"

t_sq_pos	create_pos(int x, int y)
{
	t_sq_pos	temp;

	temp.x = x;
	temp.y = y;
	return (temp);
}

t_sq_element	create_element(int x, int y, int size, bool is_obstacle)
{
	t_sq_element	temp;

	temp.pos = create_pos(x, y);
	temp.size = size;
	temp.is_obstacle = is_obstacle;
	return (temp);
}

int	get_el_index(t_sq_pos pos, t_baguette map)
{
	int	res;

	res = map.size.x * pos.y + pos.x;
	if (pos.x < 0 || pos.y < 0)
		res = -1;
	return (res);
}

t_sq_element	get_el(t_sq_pos pos, t_baguette b)
{
	const int	index = get_el_index(pos, b);

	if (index == -1)
		return (create_element(0, 0, 0, false));
	return (b.map[index]);
}
