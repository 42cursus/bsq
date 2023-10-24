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

t_sq_element	create_element(int x, int y, bool is_obstacle)
{
	t_sq_element	temp;

	temp.pos.x = x;
	temp.pos.y = y;
	temp.is_obstacle = is_obstacle;
	return (temp);
}

t_sq_pos	create_pos(int x, int y)
{
	t_sq_pos	temp;

	temp.x = x;
	temp.y = y;
	return (temp);
}

int	get_el_size_by_pos(int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	return (0);
}

//TODO
void	set_size(t_sq_element el, int size)
{
	el.size = size;
	(void)el;
}
